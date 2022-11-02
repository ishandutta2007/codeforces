#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>

using lint = long long;

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
    lint a, b;
    std::string s;
    std::cin >> n >> a >> b >> s;

    std::vector<int> hs(n + 1, 1);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') hs[i] = hs[i + 1] = 2;
    }

    lint cost = n * a + std::accumulate(hs.begin(), hs.end(), 0) * b;
    for (int i = 0; i < n; ++i) {
        if (hs[i] != hs[i + 1]) cost += a;
    }

    auto ps = runlength(hs);
    ps.erase(ps.begin());
    if (!ps.empty()) ps.pop_back();

    for (auto p : ps) {
        if (p.first == 2) continue;
        int len = p.second;
        if (len * b < a * 2) {
            cost += len * b - a * 2;
        }
    }

    std::cout << cost << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}