#include <bits/stdc++.h>

using namespace std;

int n, m, zz;
string s;
int a[28];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n >> m >> zz >> s;
        for (int i = 0; i < 28; ++i) a[i] = 0;
        for (int i = 0; i < s.size(); ++i) ++a[s[i] - 'A'];
        int ans = 1e9;
        for (int i = 0; i < 27; ++i) {
            //ignore i
            vector <bool> can(zz - a[i] + 1, 0);
            can[0] = 1;
            for (int j = 0; j < 26; ++j) if (j != i) {
                for (int k = zz - a[i]; k >= 0; --k) if (can[k]) can[k + a[j]] = 1;
            }
            for (int j = 0; j <= zz - a[i]; ++j) if (can[j]) {
                int need_n = max(0, n - j);
                int need_m = max(0, m - (zz - a[i] - j));
                if (need_n + need_m > a[i]) continue;
                ans = min(ans, need_n * need_m);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}