#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += (s[i] == '1');

    if (cnt == n) {
        std::cout << 1 << " " << n - 1 << " " << 2 << " " << n << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            continue;
        }
        if (i < n / 2) {
            std::cout << i + 2 << " " << n << " " << i + 1 << " " << n << '\n';
            return;
        } else {
            std::cout << 1 << " " << i + 1 << " " << 1 << " " << i << '\n';
            return;
        }
    }
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