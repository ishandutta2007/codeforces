#include <bits/stdc++.h>

using i64 = long long;

const i64 M = 89691488802248981, P = 26;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string t, l, r;
    std::cin >> t >> l >> r;

    int n = t.size(), x = l.size(), y = r.size();

    std::vector<bool> pref(n);
    std::vector<bool> suff(n);
    for (int i = 0; i <= n - x; i++) {
        pref[i] = true;
        for (int j = 0; j < x; j++) {
            pref[i] = (pref[i] & t[i + j] == l[j]);
        }
    }

    std::reverse(r.begin(), r.end());
    for (int i = n - 1; i >= y - 1; i--) {
        suff[i] = true;
        for (int j = 0; j < y; j++) {
            suff[i] = (suff[i] & t[i - j] == r[j]);
        }
    }

    int ans = 0;
    std::unordered_map<i64, int> occ;
    for (int i = 0; i < n; i++) {
        if (!pref[i]) continue;
        i64 hash = (i64) 1;
        for (int j = i; j < n; j++) {
            hash = (hash * (i64) P) % M + (i64) t[j];
            if (hash >= M) hash -= M;
            if (suff[j] && i + x - 1 <= j && j - y + 1 >= i) {
                ans += (occ[hash] == 0);
                occ[hash] = 1;
            }
        }
    }

    std::cout << ans << "\n";
    return 0;
}