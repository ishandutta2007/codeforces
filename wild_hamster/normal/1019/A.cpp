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
ll n,i,j,k,z,m,q,r,timer,mx,l, cnt,v,tot,x,y,INF, sz, used[55];
ll b[200500], a[200500], c[200500];
vector<ll> g[100500], f[100500];
int main() {
   // freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y);
    }
    for (int i = 2; i <= m; i++) {
        sort(g[i].begin(), g[i].end());
        f[i].push_back(0);
        for (int j = 0; j < g[i].size(); j++)
            f[i].push_back(f[i][j] + g[i][j]);
    }
    ll ans = (ll)1e+18;
    for (int i = 1; i <= n; i++) {
        ll sum = 0;
        ll cnt = g[1].size();
        for (int j = 2; j <= m; j++) {
            ll sz = g[j].size();
            if (sz >= i) {
                sum += f[j][sz-(i-1)];
                cnt += sz-(i-1);
            }
        }
        if (cnt >= i) {
            ans = min(ans, sum);
            continue;
        }
        vector<ll> ff;
        for (int j = 2; j <= m; j++) {
            ll sz=g[j].size();
            for (int k = sz-1; k > max(-1LL, sz-1-(i-1)); k--) {
                ff.push_back(g[j][k]);
            }
        }
        sort(ff.begin(), ff.end());
        for (int j = 0; j < i-cnt; j++)
            sum += ff[j];
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}