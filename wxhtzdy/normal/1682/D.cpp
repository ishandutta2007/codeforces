#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    if (s == std::string(n, '0') || std::count(s.begin(), s.end(), '1') % 2 == 1) {
        std::cout << "NO\n";
        return;
    }

    std::cout << "YES\n";

    std::vector<int> one;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            one.push_back(i);
        }
    }

    for (int i = 0; i < one.size(); i++) {
        int prv = one[i];
        int nxt = (one[i] + 1) % n;
        while (nxt != one[(i + 1) % one.size()]) {
            std::cout << prv + 1 << " " << nxt + 1 << "\n";
            prv = (prv + 1) % n;
            nxt = (nxt + 1) % n;
        }
    }

    for (int i = 1; i < one.size(); i++) {
        std::cout << (one[0] - 1 + n) % n + 1 << " " << one[i] << "\n";
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