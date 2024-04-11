#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    char next = 'a';
    for (auto& c : s) {
        if (c <= next) {
            c = next++;
        }
        if (next > 'z') break;
    }

    std::cout << (next > 'z' ? s : "-1") << std::endl;
    return 0;
}