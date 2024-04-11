#include <iostream>
#include <algorithm>
#include <string>

void solve() {
    std::string s;
    std::cin >> s;

    int ans = 0;
    for (char c = '0'; c <= '9'; ++c) {
        ans = std::max(ans, (int)std::count(s.begin(), s.end(), c));
    }

    for (char c1 = '0'; c1 <= '9'; ++c1) {
        for (char c2 = '0'; c2 <= '9'; ++c2) {
            char d1 = c1, d2 = c2;
            int cnt = 0;

            for (char c : s) {
                if (c == d1) {
                    ++cnt;
                    std::swap(d1, d2);
                }
            }

            ans = std::max(ans, cnt / 2 * 2);
        }
    }

    std::cout << s.length() - ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}