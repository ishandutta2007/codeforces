#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> p(n);
    int ans = 1;
    while (ans < n) ans *= 2;
    ans -= 1;
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
        if (p[i] != i) ans &= i;
    }
    
    std::cout << ans << "\n";
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