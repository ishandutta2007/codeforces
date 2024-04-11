#include <iostream>
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

using lint = long long;

void solve() {
    lint n;
    std::string s;
    std::cin >> n >> s;

    lint rem = n * 2;
    auto v = runlength(s);
    if (v.size() >= 2) {
        rem -= v.front().second + v.back().second + v.size() - 1;
    } else {
        rem = 0;
    }

    std::cout << n * (n - 1) / 2 - rem << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}