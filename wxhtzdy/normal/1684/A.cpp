#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.size();

    if (n == 2) {
        std::cout << s[1] << "\n";
    } else {
        std::cout << *std::min_element(s.begin(), s.end()) << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}