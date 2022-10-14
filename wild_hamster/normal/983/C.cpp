#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l, ans;
ll a[200500],  b[200500];
ll dp[2005][10005];
vector<ll> f;
ll Abs(ll x) {
    return x>0?x:-x;
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 10000; j++)
            dp[i][j] = MOD;
    }
    dp[1][b[0]] = a[0]-1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10000; j++)
        if (dp[i][j] != MOD) {
            ll cur_lev = a[i-1];
            f.clear();
            y = j;
            while (y != 0) {
                f.push_back(y%10);
                y /= 10;
            }
            ll sz = f.size();
            for (int k = 0; k < (1<<sz); k++) {
                vector<ll> next_state;
                ll min1 = 15, max1 = -15;
                for (int kk = 0; kk < sz; kk++) {
                    if ((k&(1<<kk)) != 0) {
                        min1 = min(min1, f[kk]);
                        max1 = max(max1, f[kk]);
                    } else {
                        next_state.push_back(f[kk]);
                    }
                }
                if (k == 0) {
                    min1 = cur_lev;
                    max1 = cur_lev;
                }
                next_state.push_back(b[i]);
                ll val = min(Abs(cur_lev-min1) + (max1-min1) + Abs(max1 - a[i]),
                             Abs(cur_lev-max1) + (max1-min1) + Abs(min1 - a[i]));
                sort(next_state.begin(), next_state.end());
                ll next_j = 0;
                for (int kk = 0; kk < next_state.size(); kk++)
                    next_j = next_j*10 + next_state[kk];
                if (next_j < 10000) {
                    dp[i+1][next_j] = min(dp[i+1][next_j], dp[i][j] + val);
                }
            }
        }
    }
    ll ans = MOD;
    for (int j = 0; j < 10000; j++) {
        if (dp[n][j] != MOD) {
                //cout << j << endl;
            ll cur_lev = a[n-1];
            f.clear();
            y = j;
            while (y != 0) {
                f.push_back(y%10);
                y /= 10;
            }
            ll sz = f.size();
            ll min1 = 15, max1 = -15;
            for (int k = 0; k < sz; k++) {
                min1 = min(min1, f[k]);
                max1 = max(max1, f[k]);
            }
            ll val = min(Abs(cur_lev-min1) + (max1-min1),
                     Abs(cur_lev-max1) + (max1-min1));
            ans = min(ans, dp[n][j] + val);
        }
    }
    cout << ans + n*2 << endl;
    return 0;
}