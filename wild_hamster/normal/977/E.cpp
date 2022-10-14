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
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll a[300500];
ll b[1005000], t[1005000], used[1005000];
vector<ll> g[200500];
string s;
set<ll> is_here;
void dfs(ll v) {
    if (used[v])
        return;
    used[v] = 1;
    l++;
    if (g[v].size() != 2) {
        mx = 0;
    }
    for (int i = 0; i < g[v].size(); i++) {
        dfs(g[v][i]);
    }
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    if (!used[i]) {
        mx = 1;
        l = 0;
        dfs(i);
        if (l >= 3 && mx == 1)
            ans++;
    }
    cout << ans << endl;
    return 0;
}