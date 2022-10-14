#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> s(h, std::string(w, '0'));
    s[0][0] = '1';
    s[h - 1][0] = '1';
    s[0][w - 1] = '1';
    s[h - 1][w - 1] = '1';
    for (int i = 2; i < h - 2; i += 2) {
        s[i][0] = '1';
        s[i][w - 1] = '1';
    }
    for (int i = 2; i < w - 2; i += 2) {
        s[0][i] = '1';
        s[h - 1][i] = '1';
    }

    for (int i = 0; i < h; i++) {
        std::cout << s[i] << "\n";
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