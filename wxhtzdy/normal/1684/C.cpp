#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }

    int idx = -1;
    for (int i = 0; i < n; i++) {
        if (!std::is_sorted(a[i].begin(), a[i].end())) {
            idx = i;
        }
    }

    if (idx == -1) {
        std::cout << "1 1\n";
        return;
    }

    auto b = a[idx];
    std::sort(b.begin(), b.end());

    std::vector<int> pos;
    for (int i = 0; i < m; i++) {
        if (a[idx][i] != b[i]) {
            pos.push_back(i);
        }
    }

    int x = pos[0], y = pos[1];
    for (int i = 0; i < n; i++) {
        std::swap(a[i][x], a[i][y]);
    }

    bool good = true;
    for (int i = 0; i < n; i++) {
        good &= (std::is_sorted(a[i].begin(), a[i].end()));
    }

    if (good) {
        std::cout << x + 1 << " " << y + 1 << "\n";
    } else {
        std::cout << "-1\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}