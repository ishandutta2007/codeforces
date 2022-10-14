#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    int x = k - n + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << (i == j ? x : 1) << " ";
        }
        std::cout << "\n";
    }
    return 0;
}