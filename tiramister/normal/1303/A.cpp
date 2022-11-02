#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using lint = long long;
using ldouble = long double;

std::vector<std::pair<char, int>> runlength(const std::string& s) {
    std::vector<std::pair<char, int>> res;
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
    std::string s;
    std::cin >> s;

    auto run = runlength(s);
    if (!run.empty() && run.front().first == '0') run.erase(run.begin());
    if (!run.empty() && run.back().first == '0') run.pop_back();

    int ans = 0;
    for (auto p : run) {
        if (p.first == '0') ans += p.second;
    }

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}