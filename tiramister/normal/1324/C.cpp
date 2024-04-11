#include <iostream>
#include <vector>
#include <string>

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.length();
    std::vector<int> pos{0};
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == 'R') pos.push_back(i);
    }
    pos.push_back(n + 1);

    int ans = 0;
    for (int i = 0; i + 1 < (int)pos.size(); ++i) {
        ans = std::max(ans, pos[i + 1] - pos[i]);
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