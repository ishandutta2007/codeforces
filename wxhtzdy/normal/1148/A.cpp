#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 a, b, c;
    std::cin >> a >> b >> c;

    if (a == b) {
        std::cout << a + b + c * 2 << "\n";
    } else {
        if (a > b) {
            std::cout << b * 2 + c * 2 + 1 << "\n";
        } else {
            std::cout << a * 2 + c * 2 + 1 << "\n";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}