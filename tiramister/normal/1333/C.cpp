#include <iostream>
#include <vector>
#include <set>

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<lint> xs(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        lint x;
        std::cin >> x;
        xs[i] = xs[i - 1] + x;
    }

    std::set<lint> ss;
    lint ans = 0;
    int l = 0, r = 0;
    while (l <= n) {
        while (r <= n) {
            if (ss.count(xs[r])) break;
            ss.insert(xs[r++]);
        }

        ans += r - l - 1;
        ss.erase(xs[l++]);
    }

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}