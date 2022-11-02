#include <iostream>
#include <algorithm>
#include <string>

void solve() {
    std::string s;
    std::cin >> s;

    if (std::all_of(s.begin(), s.end(),
                    [&](const auto c) { return c == s.front(); })) {
        std::cout << s << std::endl;
    } else {
        for (int i = 0; i < (int)s.length(); ++i) {
            std::cout << "01";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}