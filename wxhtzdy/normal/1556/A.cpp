#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int a, b;
    std::cin >> a >> b;

    if (a % 2 != b % 2) {
        std::cout << "-1\n";
        return;
    }

    if (a == 0 && b == 0) {
        std::cout << "0\n";
        return;
    }

    std::cout << (a == b ? 1 : 2) << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt;
    std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}