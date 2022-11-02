#include <iostream>
#include <algorithm>
#include <vector>

using lint = long long;

void solve() {
    int n, m, k;
    lint a, b;
    std::cin >> n >> m >> a >> k >> b;

    std::vector<int> xs(n), ys(m);
    for (auto& x : xs) {
        std::cin >> x;
        ++x;
    }
    xs.insert(xs.begin(), 0);
    xs.push_back(1);

    for (auto& y : ys) {
        std::cin >> y;
        ++y;
    }
    ys.insert(ys.begin(), 0);
    ys.push_back(1);

    n += 2;
    m += 2;

    std::vector<int> revx(n);
    for (int i = 0; i < n; ++i) {
        revx[xs[i]] = i;
    }

    lint ans = 0;
    for (int j = 0; j + 1 < m; ++j) {
        int l = revx[ys[j]],
            r = revx[ys[j + 1]];

        if (r < l) {
            std::cout << -1 << "\n";
            return;
        }

        lint len = r - l - 1;
        if (len == 0) continue;

        bool emax = false;
        {
            int max = *std::max_element(xs.begin() + l + 1, xs.begin() + r);
            if (xs[l] > max || xs[r] > max) emax = true;
        }

        if (len < k && !emax) {
            std::cout << -1 << "\n";
            return;
        }

        if (a >= k * b) {
            ans += (emax ? len * b : a + (len - k) * b);
        } else {
            ans += (len / k) * a + (len % k) * b;
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}