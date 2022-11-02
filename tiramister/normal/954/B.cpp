#include <iostream>
#include <string>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    int ans = n;
    for (int len = 1; len <= n; ++len) {
        std::string t = s.substr(0, len);
        if (t + t == s.substr(0, len * 2)) {
            ans = std::min(ans, len + 1 + (n - len * 2));
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}