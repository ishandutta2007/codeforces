#include <iostream>
#include <algorithm>
#include <string>

void solve() {
    std::string s;
    std::cin >> s;

    int t = std::min(std::count(s.begin(), s.end(), '0'),
                     std::count(s.begin(), s.end(), '1'));

    std::cout << (t % 2 == 0 ? "NET" : "DA") << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}