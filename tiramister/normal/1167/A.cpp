#include <iostream>
#include <string>

int main() {
    int q;
    std::cin >> q;
    while (q--) {
        int n;
        std::string s;
        std::cin >> n >> s;
        while (!s.empty() && s.front() != '8') {
            s.erase(s.begin());
        }
        std::cout << (s.length() >= 11 ? "YES" : "NO") << std::endl;
    }
    return 0;
}