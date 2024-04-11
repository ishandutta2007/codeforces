#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int x = abs(n / 2 - i);
        for (int j = 0; j < x; j++) {
            std::cout << "*";
        }
        for (int j = 0; j < n - 2 * x; j++) {
            std::cout << "D";
        }
        for (int j = 0; j < x; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    return 0;
}