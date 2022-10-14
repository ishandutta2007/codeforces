#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.size(), x;
    std::cin >> x;

    std::string ans = "";
    for (int i = 0; i < n; i++) {
        bool ok = true;

        if (i - x >= 0 && s[i - x] == '0') ok = false;
        if (i + x < n && s[i + x] == '0') ok = false;

        ans += (ok ? '1' : '0');
    }

    std::string ns = "";
    for (int i = 0; i < n; i++) {
        bool ok = false;

        if (i - x >= 0 && ans[i - x] == '1') ok = true;
        if (i + x < n && ans[i + x] == '1') ok = true;

        ns += (ok ? '1' : '0');
    }

    if (s == ns) std::cout << ans << "\n";
    else std::cout << -1 << "\n";
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