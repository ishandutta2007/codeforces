#include <iostream>
#include <algorithm>
#include <string>

const std::string vowel = "aeiouy";

void solve() {
    int n;
    std::cin >> n;

    bool prev = false;
    while (n--) {
        char c;
        std::cin >> c;
        bool cur = std::count(vowel.begin(), vowel.end(), c);
        if (!prev || !cur) std::cout << c;
        prev = cur;
    }
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}