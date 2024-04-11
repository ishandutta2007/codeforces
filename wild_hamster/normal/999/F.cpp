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
#define ROW 5
#define COL 30000
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,t,s,tot,x,y,INF, ans;
ll a[1200005], b[1205000], w[1205000];
ll dp[5005][5005];
vector<ll> g[5005], gr[5005];
ll gcd(ll a, ll b) {
    return (b==0?a:gcd(b,a%b));
}
int main() {

    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    for (int i = 0; i < n*k; i++) {
        cin >> x;
        a[x]++;
    }

    for (int i = 0; i < n; i++) {
        cin >> x;
        b[x]++;
    }

    for (int i = 1; i <= k; i++)
        cin >> w[i];
    ll ans = 0;
    for (int i = 1; i <= 100000; i++) {
        if (b[i] > 0) {
            ll tot = a[i];
            if (a[i] >= b[i]*k) {
               ans += w[k]*b[i];
            } else {
                ll need = a[i];
                ll l = b[i];
                for (int i1 = 0; i1 <= l; i1++)
                    for (int j1 = 0; j1 <= need; j1++)
                        dp[i1][j1] = 0;
                for (int i1 = 0; i1 < l; i1++)
                    for (int k1 = 0; k1 <= k; k1++)
                        for (int j1 = 0; j1+k1 <= need; j1++)
                            dp[i1+1][j1+k1] = max(dp[i1+1][j1+k1], dp[i1][j1] + w[k1]);
                ans += dp[l][need];
            }
        }
    }
    cout << ans << endl;
    return 0;
}