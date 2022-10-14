#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> a(4);
    for (int i = 0; i < 4; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < (1 << 4); i++) {
        int x = 0, y = 0;

        for (int j = 0; j < 4; j++) {
            if (i & (1 << j)) x += a[j];
            else y += a[j];
        }

        if (x == y) {
            std::cout << "YES\n";
            return 0;
        }
    }

    std::cout << "NO\n";
    return 0;
}