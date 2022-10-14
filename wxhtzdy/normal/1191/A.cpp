#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    if (n % 4 == 0) {
        std::cout << "1 A";
    }
    if (n % 4 == 1) {
        std::cout << "0 A";
    }
    if (n % 4 == 2) {
        std::cout << "1 B";
    }
    if (n % 4 == 3) {
        std::cout << "2 A";
    }

    return 0;
}