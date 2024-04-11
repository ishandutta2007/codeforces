#include <iostream>
#include <string>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    int zs = 0;
    for (char c : s) {
        if (c == '0') ++zs;
    }

    if (n != zs) std::cout << 1;
    while (zs--) std::cout << 0;
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}