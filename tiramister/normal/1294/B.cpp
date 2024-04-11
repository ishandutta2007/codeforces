#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> ps(n);
    for (auto& p : ps) std::cin >> p.first >> p.second;
    std::sort(ps.begin(), ps.end());

    std::string ans;
    int x = 0, y = 0;
    for (auto p : ps) {
        if (p.second < y) {
            std::cout << "NO" << std::endl;
            return;
        }
        while (x < p.first) {
            ans.push_back('R');
            ++x;
        }
        while (y < p.second) {
            ans.push_back('U');
            ++y;
        }
    }

    std::cout << "YES" << std::endl
              << ans << std::endl;
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