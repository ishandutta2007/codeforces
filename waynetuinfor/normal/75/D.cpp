#include <bits/stdc++.h>
using namespace std;

const int maxm = 25e4 + 10, maxn = 50 + 10, maxl = 5000 + 10;
const long long inf = 1e18 + 1;
long long s[maxn], ss[maxm], dps[maxn], pref[maxn], suff[maxn], dp[maxm];
int a[maxn][maxl], ind[maxm];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int l; cin >> l;
        long long prefmin = 0;
        long long scur = 0;
        dps[i] = -inf;
        pref[i] = -inf;
        for (int j = 1; j <= l; ++j) {
            cin >> a[i][j]; scur += a[i][j];
            pref[i] = max(pref[i], scur);
            dps[i] = max(dps[i], scur - prefmin);
            prefmin = min(prefmin, scur);
        }
        s[i] = scur;
        suff[i] = scur;
        for (int j = 1; j <= l - 1; ++j) {
            scur -= a[i][j];
            suff[i] = max(suff[i], scur);
        }
    }
    for (int i = 1; i <= m; ++i) cin >> ind[i];
    for (int i = 1; i <= m; ++i) ss[i] = ss[i - 1] + s[ind[i]];
    long long prefmax = 0;
    for (int i = 1; i <= m; ++i) {
        dp[i] = ss[i - 1] + pref[ind[i]] + prefmax;
        prefmax = max(prefmax, -ss[i] + suff[ind[i]]);
    }
    long long ans = -inf;
    for (int i = 1; i <= m; ++i) ans = max(ans, max(dp[i], dps[ind[i]]));
    cout << ans << endl;
    return 0;
}