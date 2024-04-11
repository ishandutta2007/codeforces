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
typedef int ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,t,s,tot,x,y;
ll a[200005];
vector<ll> g[100500];
void dfs(ll v, ll lvl, ll p = -1) {
    if (a[v] > 0) {
        if (lvl > a[v])
            r = lvl - a[v];
        return;
    }
    a[v] = lvl;
    for (int i = 0; i < g[v].size(); i++) {
        ll to = g[v][i];
        if (to != p) {
            dfs(to, lvl+1, v);
        }
    }
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    if (n != m) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (r < 3) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "FHTAGN!" << endl;
    return 0;
}