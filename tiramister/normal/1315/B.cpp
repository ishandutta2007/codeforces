#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

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
    int a, b, c;
    std::cin >> a >> b >> c;

    std::string s;
    std::cin >> s;
    int n = s.length();

    s.pop_back();
    std::reverse(s.begin(), s.end());
    auto ps = runlength(s);

    for (auto p : ps) {
        c -= (p.first == 'A' ? a : b);
        if (c < 0) break;
        n -= p.second;
    }
    std::cout << n << std::endl;
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