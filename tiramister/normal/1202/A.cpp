#include <iostream>
#include <string>

void solve() {
    std::string s, t;
    std::cin >> s >> t;

    while (t.back() == '0') {
        s.pop_back();
        t.pop_back();
    }

    int ans = 0;
    while (s.back() == '0') {
        ++ans;
        s.pop_back();
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