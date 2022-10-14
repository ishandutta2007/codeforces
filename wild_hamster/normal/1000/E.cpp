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
#define MOD 998244353
#define ROW 5
#define COL 30000
typedef int ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,tot,x,y,INF, ans;
ll a[300005], res[305000], b[300500], tin[305000], fup[300500], used[300500], col[300500], w[300500];
vector<ll> g[300500], tree[300500], gr[300500];
map<pii, ll> is_bridge;
vector<pii> bridges;
void dfs (int v, int p = -1) {
	used[v] = 1;
	tin[v] = fup[v] = timer++;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (to == p)  continue;
		if (used[to])
			fup[v] = min (fup[v], tin[to]);
		else {
			dfs (to, v);
			fup[v] = min (fup[v], fup[to]);
			if (fup[to] > tin[v]) {
                is_bridge[mp(v,to)] = is_bridge[mp(to, v)] = 1;
                bridges.push_back(mp(v,to));
			}
		}
	}
}

void dfs2(int v) {
    if (used[v])
        return;
    col[v] = tot;
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        ll to = g[v][i];
        if (is_bridge.find(mp(v, to)) == is_bridge.end())
            dfs2(to);
    }
}

void find_bridges() {
	timer = 0;
	for (int i=1; i <= n; ++i)
		if (!used[i])
			dfs (i);
}

ll dfs_tree(ll v, ll p = -1) {
    ll max1 = -1;
    ll max2 = -1;
    for (int i = 0; i < tree[v].size(); i++) {
        ll to = tree[v][i];
        if (to != p) {
            ll val = dfs_tree(to, v);
            if (val > max1) {
                max2 = max1;
                max1 = val;
            } else if (val > max2) {
                max2 = val;
            }
        }
    }
    //cout << v << " " << max1 << " " << max2 << endl;
    w[v] = max1 + max2 + 2;
    return max1 + 1;
}

int main() {

    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
        a[i] = x;
        b[i] = y;
    }
    find_bridges();
    for (int i = 1; i <= n; i++)
        used[i] = 0;
    tot = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            tot++;
            dfs2(i);
        }
    }
    for (int i = 0; i < bridges.size(); i++) {
        ll x = col[bridges[i].X];
        ll y = col[bridges[i].Y];
        //cout << x << " " << y << endl;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    ll ans = dfs_tree(1);
    for (int i = 1; i <= tot; i++)
        ans = max(ans, w[i]);
    cout << ans << endl;
    return 0;
}