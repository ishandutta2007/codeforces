#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        cnt[a[i]]++;
    }

    int s = 0, t = 0;
    for (auto& c : cnt) {
        if (c.second >= 2) {
            t++;
        } else {
            s++;
        }
    }

    std::cout << t + (s + 1) / 2 << "\n";
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