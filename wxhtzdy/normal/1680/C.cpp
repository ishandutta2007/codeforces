#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
 
    int n = s.size();
    std::vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        cnt[i + 1] = cnt[i] + (s[i] == '0');
    } 
    std::vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            pos.push_back(i + 1);
    }
 
    auto check = [&](int x) {
        if (x >= pos.size())
            return true;
        int sz = pos.size();
        for (int i = 0; i <= x; i++) {
            int l = pos[i];
            int r = (i == x + 1 ? n : pos[sz - (x + 1 - i)]);
            if (cnt[r] - cnt[l] <= x)
                return true;
        }
        return false;
    };
 
    int l = -1, r = n;
    while (r - l > 1) {
        int m = (l + r + 1) >> 1;
        if (check(m)) 
            r = m;
        else
            l = m;
    }
    std::cout << r << "\n";
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