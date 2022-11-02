#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
std::vector<std::pair<T, int>> runlength(const std::vector<T>& s) {
    std::vector<std::pair<T, int>> res;
    for (char c : s) {
        if (res.empty() || c != res.back().first) {
            res.emplace_back(c, 1);
        } else {
            ++res.back().second;
        }
    }
    return res;
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;
    auto ps = runlength(xs);

    xs.clear();
    std::transform(ps.begin(), ps.end(), std::back_inserter(xs),
                   [](auto p) { return p.second; });

    int m = xs.size();
    int it = 0;

    int g = xs[it++];

    int s = 0;
    while (it < m && s <= g) s += xs[it++];

    int b = 0;
    while (it < m && b <= g) b += xs[it++];

    int sum = g + s + b;
    if (s <= g || b <= g || sum * 2 > n) {
        std::cout << "0 0 0\n";
        return;
    }

    while (it < m) {
        if ((sum + xs[it]) * 2 > n) break;
        b += xs[it];
        sum += xs[it++];
    }

    std::cout << g << " " << s << " " << b << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}