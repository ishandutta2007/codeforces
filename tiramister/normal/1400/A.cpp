#include <iostream>
#include <string>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::string ans(n, '*');
    for (int i = 0; i < n; ++i) {
        ans[i] = s[i * 2];
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