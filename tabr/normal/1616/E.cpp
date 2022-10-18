#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t;
        cin >> t;
        {
            string m = s;
            sort(m.begin(), m.end());
            if (m >= t) {
                cout << -1 << '\n';
                continue;
            }
        }
        vector<vector<int>> a(26);
        for (int i = 0; i < n; i++) {
            a[s[i] - 'a'].emplace_back(i);
        }
        vector<int> idx(26);
        auto f = [&](int x) {
            long long res = 0;
            for (int i = 0; i < 26; i++) {
                auto beg = a[i].begin() + idx[i];
                res += (int) (lower_bound(beg, a[i].end(), x) - beg);
            }
            return res;
        };
        long long ans = (long long) 1e18;
        long long same = 0;
        for (int i = 0; i < n; i++) {
            int c = t[i] - 'a';
            long long need = (long long) 1e18;
            for (int j = 0; j < c; j++) {
                if (idx[j] == (int) a[j].size()) {
                    continue;
                }
                need = min(need, f(a[j][idx[j]]));
            }
            ans = min(ans, same + need);
            if (idx[c] == (int) a[c].size()) {
                break;
            }
            same += f(a[c][idx[c]]);
            idx[c]++;
        }
        cout << ans << '\n';
    }
    return 0;
}