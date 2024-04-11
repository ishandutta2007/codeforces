#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int bal = 0, mn = 0, mx = -1e9;
    for (int i = 0; i < n; i++) {
        bal += (s[i] == '+' ? +1 : -1);
        mn = std::min(mn, bal);
        mx = std::max(mx, bal);
    }

    std::cout << bal - mn << "\n";
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