#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    n *= 2;

    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a, a + n);

    auto Solve = [&](int sum, int ind) {
        std::vector<std::pair<int, int>> ans;
        ans.push_back({a[ind], a[n - 1]});

        std::map<int, int> mp;
        for (int i = 0; i < n - 1; i++) {
            if (i != ind) {
                ++mp[a[i]];
            }
        }

        int x = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (!mp[a[i]])
                continue;

            if (!mp[x - a[i]] || (a[i] * 2 == x && mp[a[i]] == 1)) {
                ans.clear();
                return ans;
            }

            --mp[a[i]];
            --mp[x - a[i]];
            ans.push_back({x - a[i], a[i]});
            x = a[i];
        }

        return ans;
    };

    for (int i = 0; i + 1 < n; i++) {
        auto ans = Solve(a[i] + a[n - 1], i);

        if (!ans.empty()) {
            std::cout << "YES\n" << a[i] + a[n - 1] << "\n";
            for (int i = 0; i * 2 < n; i++) {
                std::cout << ans[i].first << " " << ans[i].second << "\n";
            }
            return;
        }
    }

    std::cout << "NO\n";
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