//
// Created by wangzijian on 2023/9/6.
//


// bool = char 为8bit
// int 为32bit
// double 为64bit

//
// Created by wangzijian on 2023/9/6.
//

#include "iostream"
#include "string"
#include "chrono"
#include "vector"
#include "map"
#include <unordered_map>


using namespace std;


void copy_func() {
    int v1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int v2[10];

    for (int i = 0; i < 10; i++) {
        v2[i] = v1[i];
    }

}

// 使用std的内置函数实现
void copy_func_update() {
    int v1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int v2[10];

    std::copy(std::begin(v1), std::end(v1), std::begin(v2));

}

// 将记录函数执行时间的封装为函数
// 这里的func需要根据你原来的func进行调整
// 将函数作为参数传入函数
void measure_func_time(void (*func)(), string function_name) {
    auto start_time = std::chrono::high_resolution_clock::now();

    // 调用要测量时间的函数
    func();

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    std::cout << function_name << " execution time: " << duration.count() << " milliseconds" << std::endl;
}

// 原始的for循环打印数组的方法
void print_for(const int array[], int size) {
    // 确保数组大小大于等于10
    if (size < 10) {
        std::cerr << "数组大小小于10，无法打印前10个元素。" << std::endl;
        return;
    }

    std::cout << "前10个元素为: ";
    for (int i = 0; i < 10; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

// 更为简单的打印数组元素的方法
void print_for_update() {
    int v1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (auto x: v1) {
        cout << x << endl;
    }
}

// 统计字符p在字符数组中出现的字数
void count_p(char *p, char word) {
    // 定义变量最好初始化
    int count = 0;

    if (p == nullptr)
        cout << "it's a nullptr!" << endl;

    for (; *p != 0; p++) {
        if (*p == word)
            count++;
    }
    cout << "the num is " << count << endl;
}

// 构建自己的命名空间
namespace My_code{
    // 定义命名空间中的类
    class complex{};

    // 定义函数
    int main();
}

int My_code::main() {
    cout<<"this is namespace's func main"<<endl;
    return 0;
}


// 抽象类的定义
// 抽象类的使用只能用派生类来实现
// 也就是子类
class Container{
public:
    // 定义纯虚函数
    virtual double& operator[](int) = 0;

    // 定义纯虚析构函数
    virtual ~Container(){};
};


class VectorContainer:public Container{
private:
    double* array;
public:
    // 构造函数
    VectorContainer(int size) {
        array = new double[size];
    }

    // 实现抽象类中的纯虚函数
    double& operator[](int index) override {
        return array[index];
    }

    // 析构函数
    ~VectorContainer() {
        delete[] array;
    }
};


// 定义抽象类
class shape{
public:
    virtual void center() const = 0;
};

// 迭代器
//迭代器
vector<string::iterator> find_all(string &s,char c){
    vector<string::iterator> res;
    for (auto p = s.begin(); p!=s.end() ; ++p) {
        if (*p == c) res.push_back(p);
    }
    return res;
}

int main() {
    cout << "hello C11" << endl;

    // 定义输入字符数组
    char v[6] = {'1', 't'};

    // 定义指向字符的指针
    char *p;

    // 将p指向数组元素
    p = &v[0];
    cout << *p << endl;

    copy_func();
    copy_func_update();

    // for循环用时
    measure_func_time(copy_func, "for func time");
    measure_func_time(copy_func_update, "update time ");

    print_for_update();

    // 初始化指针的时候要么直接指定要么赋值nullptr
    double *pd = nullptr;

    char myString[] = "Hello, World!";
    count_p(myString, 'o');

    // enum枚举
    enum class Color{red,green,blue};
    Color color = Color::red;

    // 这两种red的value不是一样的
    enum class reverseColor{blue,green,red};
    reverseColor reversecolor = reverseColor::red;

    // 测试namespace的函数
    int returnNum = My_code::main();

    // 使用标准库
    string name = "wang zijian";

    string s = name.substr(5,10);
    cout<<s<<endl;
    name.replace(5,10,"yiling");
    cout<<name<<endl;
    // 接受char类型的字符
    name[0] = toupper(name[0]);
    cout<<name<<endl;

    // 读取一整行
    string yourname;
//    getline(cin,yourname);
    cout<<"hello " <<yourname<<"!"<<endl;

    // 基础map的语法
    map<int, string> phonebook{
            {1,"wangzijian"},
            {2,"wangzijian2"}
    };
    std::cout << "Value associated with key 2: " << phonebook[2] << std::endl;

    // 哈希map的语法
    std::unordered_map<int, std::string> myUnorderedMap;

    // 插入键值对
    myUnorderedMap[1] = "One";
    myUnorderedMap[2] = "Two";
    myUnorderedMap[3] = "Three";

    // 遍历map的方法
    // 遍历键值对
    for (const auto& pair : myUnorderedMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    string testForfind = "wangzijian";
    vector<string::iterator> test  = find_all(testForfind,'c');





}