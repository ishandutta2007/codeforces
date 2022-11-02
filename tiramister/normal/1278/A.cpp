#include <iostream>
#include <algorithm>
#include <string>

void solve() {
    std::string s, h;
    std::cin >> s >> h;
    std::sort(s.begin(), s.end());

    int n = s.length(), m = h.length();
    for (int i = 0; i + n <= m; ++i) {
        auto t = h.substr(i, n);
        std::sort(t.begin(), t.end());

        if (s == t) {
            std::cout << "YES" << std::endl;
            return;
        }
    }
    std::cout << "NO" << std::endl;
}

int main() {
    int q;
    std::cin >> q;
    while (q--) solve();
    return 0;
}