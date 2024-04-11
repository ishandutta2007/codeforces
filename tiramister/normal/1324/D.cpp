#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <map>

template <class T>
std::map<T, int> compress(std::vector<T>& v) {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::map<T, int> rev;
    for (int i = 0; i < (int)v.size(); ++i) rev[v[i]] = i;
    return rev;
}

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n), ys(n);
    for (auto& x : xs) std::cin >> x;
    for (auto& y : ys) std::cin >> y;

    std::vector<int> ds(n), ps;
    for (int i = 0; i < n; ++i) {
        ds[i] = xs[i] - ys[i];
        ps.push_back(ds[i]);
        ps.push_back(-ds[i]);
    }

    auto revp = compress(ps);
    int m = ps.size();

    std::vector<lint> sum(m + 1, 0);
    for (auto d : ds) ++sum[revp[-d] + 1];
    for (int i = 0; i < m; ++i) sum[i + 1] += sum[i];

    lint ans = 0;
    for (auto d : ds) {
        ans += sum[revp[d]];
        if (d > -d) --ans;
    }
    std::cout << ans / 2 << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}