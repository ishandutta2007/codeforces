#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l, ans, cnt;
vector<ll> f;
vector<ll> g[100500];
ll a[100500], w[100500];
ll sum[55][55];
ll t[100500];
ll dp[55][55];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    //cin >> n >> k;
    /*n = 50; k = 25;
    srand(time(0));
    for (int i = 0; i < n; i++)
        a[i] = 1LL*rand()*rand()*rand()*rand();*/
    for (int i = 0; i < n; i++) {
        ll x = 0;
        for (int j = i; j < n; j++) {
            x += a[j];
            sum[i][j] = x;
        }
    }
    ll ans = 0;
    for (int ii = 60; ii >= 0; ii--) {
        ans |= (1LL<<ii);
        for (int i = 0; i <= k; i++)
            for (int j = 0; j <= n; j++)
                dp[j][i] = 0;
        dp[0][0] = 1;
        //cout << ans << endl;
        for (int i = 1; i <= k; i++)
            for (int j = 0; j <= n; j++)
                for (int l = 0; l <= j; l++) {
                    if (dp[l][i-1] == 1 && ((sum[l][j] & ans) == ans))
                        dp[j+1][i] = 1;
                }
        /*for (int i = 0; i <= k; i++)
            for (int j = 0; j <= n; j++)
                cout << j << " " << i << " " << dp[j][i] << endl;*/
        if (!dp[n][k])
            ans -= (1LL<<ii);
    }
    /*for (int i = 0; i <= n; i++)
        for (int l = 0; l <= k; l++) {
        auto itr = dp[i][l].end();

        if (dp[i][l].size() >= 1) {
        itr--;
        cout << i << " " << " " << l << " " << *itr << endl;
        }
    }*/
    cout << ans << endl;
    return 0;
}