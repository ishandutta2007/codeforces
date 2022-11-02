#include <iostream>
#include <string>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;

    int h = 0;
    for (char c : s) {
        std::cout << ((c == ')') + h) % 2;
        h += (c == ')' ? -1 : 1);
    }
    std::cout << std::endl;
    return 0;
}