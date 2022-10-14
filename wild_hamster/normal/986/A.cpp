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
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l, cnt,s;
vector<ll> g[100500], f[100500], ff;
ll a[100500], b[105][100500];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m >> k >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[a[i]].push_back(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++)
            b[i][j] = -1;
    }
    for (int i = 1; i <= k; i++) {
        ll cnt = 0;
        ff.clear();
        for (int j = 0; j < f[i].size(); j++) {
            ff.push_back(f[i][j]);
            b[i][f[i][j]] = 0;
        }
        while (cnt < ff.size()) {
            ll v = ff[cnt++];
            ll val = b[i][v];
            for (int j = 0; j < g[v].size(); j++) {
                ll to = g[v][j];
                if (b[i][to] == -1) {
                    b[i][to] = val+1;
                    ff.push_back(to);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ff.clear();
        for (int j = 1; j <= k; j++) {
            ff.push_back(b[j][i]);
        }
        ll ans = 0;
        sort(ff.begin(), ff.end());
        for (int j = 0; j < s; j++)
            ans += ff[j];
        cout << ans << " ";
    }
    return 0;
}