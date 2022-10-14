#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<std::vector<int>> pos(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        pos[a[i]].push_back(i);
    }

    std::vector<int> f(n + 1, n + 1);
    for (int i = n; i >= 1; i--) {
        if (pos[i].empty()) {
            continue;
        }

        int mx = std::max(pos[i][0] + 1, n - pos[i].back());
        for (int j = 1; j < pos[i].size(); j++) {
            mx = std::max(mx, pos[i][j] - pos[i][j - 1]);
        }

        f[mx] = i;
    }

    for (int i = 1; i <= n; i++)
        f[i] = std::min(f[i], f[i - 1]);

    for (int i = 1; i <= n; i++) {
        std::cout << (f[i] == n + 1 ? -1 : f[i]) << " \n"[i == n];
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