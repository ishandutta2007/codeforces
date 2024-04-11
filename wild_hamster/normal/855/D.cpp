#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define SQ 320
#define N 8388607
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx;
ll a[100500], tin[100500], tout[100500], w[100500], lvl[100500], up[100500][20];
vector<pii> g[100500];
vector<ll> f;
ll l = 18;

void dfs (int v, int lv, int p) {
	tin[v] = ++timer;
	lvl[v] = lv;
	up[v][0] = p;
	for (int i=1; i<=l; ++i)
		up[v][i] = up[up[v][i-1]][i-1];
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i].X;
		int val = g[v][i].Y;
		if (to != p)
        {

			w[to] = w[v] + val;
			dfs (to, lv+1, v);
        }
	}
	tout[v] = ++timer;
}

bool upper (int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
	if (upper (a, b))  return a;
	if (upper (b, a))  return b;
	for (int i=l; i>=0; --i)
		if (! upper (up[a][i], b))
			a = up[a][i];
	return up[a][0];
}

int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> x >> y;
        if (x != -1)
        {
            g[i].push_back(mp(x,y));
            g[x].push_back(mp(i,y));
        } else
        {
            f.push_back(i);
        }
    }
    for (i = 0; i < f.size(); i++)
        g[0].push_back(mp(f[i], 0));
    dfs(0, 0, 0);
    //for (i = 1; i <= 3; i++)
    //    cout << w[i] << endl;
    cin >> q;
    for (i = 0; i < q; i++)
    {
        ll test, x, y;
        scanf("%d %d %d",&test,&x,&y);
        if (x == y)
        {
            cout << "NO" << endl;
            continue;
        }
        if (test == 2)
        {
            ll lc = lca(x, y);
            if (w[x] - w[lc] == 0 && w[y] - w[lc] == lvl[y] - lvl[lc] && !upper(y, x) && lc != 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        } else
        {
            if (upper(x, y) && w[x]-w[y] == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}