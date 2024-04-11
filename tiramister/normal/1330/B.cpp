#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    auto judge = [&](int l, int r) {
        int len = r - l;
        std::set<int> s;
        for (int i = l; i < r; ++i) {
            auto x = xs[i];
            if (x > len || s.count(x)) return false;
            s.insert(x);
        }
        return true;
    };

    int m = *std::max_element(xs.begin(), xs.end());

    std::set<std::pair<int, int>> ans;
    if (judge(0, m) && judge(m, n)) ans.emplace(m, n - m);
    if (judge(0, n - m) && judge(n - m, n)) ans.emplace(n - m, m);

    std::cout << ans.size() << std::endl;
    for (auto p : ans) {
        std::cout << p.first << " " << p.second << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}