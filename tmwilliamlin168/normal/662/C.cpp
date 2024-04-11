#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")
 
#include <bits/stdc++.h>
 
#define f first
#define s second
 
#define pb push_back
#define pp pop_back
#define mp make_pair
 
#define sz(x) (int)x.size()
#define sqr(x) ((x) * 1ll * (x))
#define all(x) x.begin(), x.end()
 
#define Kazakhstan ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
#define nl '\n'
#define ioi exit(0);
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
const int N = (int)1e5 + 7;
const int mxMask = (int)(1 << 20);
 
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;
 
const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
 
using namespace std;
 
int n, m;
int col[N], cnt[mxMask];
 
int dp[22][mxMask], nxt[22][mxMask];
int all[mxMask];
 
int cont[22][2];
int main() {
    #ifdef IOI2018
        freopen ("in.txt", "r", stdin);
    #endif
    Kazakhstan
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '1') col[j] |= 1 << i;
 
            cont[i][s[j] - '0']++;
        }
    }
    for (int i = 0; i < m; i++) {
        cnt[col[i]]++;
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        dp[0][mask] += cnt[mask];
 
        /// counting all
        for (int i = 0; i < n; i++) {  
            if (mask & (1 << i)) all[mask] += cont[i][0];
            else all[mask] += cont[i][1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int cnt = 0; cnt <= n / 2; cnt++) {
                if (dp[cnt][mask]) {
                    { /// do not change
                        int has = (mask & (1 << i)) > 0;
                        int nxtMask = has ? mask ^ (1 << i) : mask;
                        nxt[cnt + has][nxtMask] += dp[cnt][mask];
                    }
 
                    { /// do change
                        int has = (mask & (1 << i)) > 0;
                        int nxtMask = !has ? mask ^ (1 << i) : mask;
                        nxt[cnt + !has][nxtMask] += dp[cnt][mask];
                    }
                }
            }
        }
        memcpy(dp, nxt, sizeof(dp));
        memset(nxt, 0, sizeof(nxt));
    }
    int ans = inf;
    for (int mask = 0; mask < (1 << n); mask++) {
        int c = 0, s = 0;
        for (int i = 0; i <= n / 2; i++) {
            c += dp[i][mask];
            s += dp[i][mask] * i;
        }
        ans = min(ans, (m - c) * n - (all[mask] - s) + s);
    }
    cout << ans;
    ioi
}