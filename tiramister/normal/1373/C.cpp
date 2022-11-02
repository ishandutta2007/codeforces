#include <iostream>
#include <vector>
#include <string>

using lint = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.length();

    int cur = 0, lev = 0;
    std::vector<int> xs(n);

    for (int i = 0; i < n; ++i) {
        xs[i] = lev;

        if (s[i] == '+') {
            ++cur;
        } else {
            --cur;
        }

        lev = std::max(lev, -cur);
    }

    lint ans = 0;
    for (auto x : xs) ans += lev - x + 1;
    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}