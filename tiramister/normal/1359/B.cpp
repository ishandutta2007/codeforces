#include <iostream>
#include <vector>
#include <string>

void solve() {
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;
    y = std::min(y, x * 2);

    int ans = 0;
    while (n--) {
        std::string s;
        std::cin >> s;

        int i = 0;
        while (i < m) {
            if (s[i] == '*') {
                ++i;
            } else if (s.substr(i, 2) == "..") {
                i += 2;
                ans += y;
            } else {
                ++i;
                ans += x;
            }
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}