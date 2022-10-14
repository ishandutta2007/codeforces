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
typedef int ll;
using namespace std;
ll n,i,j,k,z,m,q,r,timer, cnt,v,tot,x,y,xx, yy,INF, sz;
long long sum;
ll a[500500], b[500500], p[500500], p1[500500], lvl[500500];
ll tin[500500], tout[500500], up[500500][21],  ass[500500], say[500500][21];
vector<ll> g[500500], vals[500500], dels[500500];
vector<pair<pii, ll> > mag;
multiset<ll> magic[500500];
const int l = 20;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}

int dsu_get (int v) {
	return (v == p[v]) ? v : (p[v] = dsu_get (p[v]));
}

void dsu_unite (int a, int b) {

	a = dsu_get (a);
	b = dsu_get (b);
	if (rand() & 1)
		swap (a, b);
	if (a != b)
		p[a] = b;
}

void dfs (int v, int lv, int p = 1) {
    lvl[v] = lv;
	tin[v] = ++timer;
	up[v][0] = p;
	for (int i=1; i<=l; ++i)
		up[v][i] = up[up[v][i-1]][i-1];
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (to != p)
			dfs (to, lv+1, v);
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

void lol(ll v, ll depth, ll val) {
    if (depth == 0)
        return;
    for (int i = 20; i >= 0; i--) {
        if (depth >= (1<<i)) {
            say[v][i] = min(say[v][i], val);
            depth -= (1<<i);
            v = up[v][i];
        }
    }
}

void dfs2(ll v, ll p = -1) {
    for (int i = 0; i < g[v].size(); i++) {
        ll to = g[v][i];
        if (to != p) {
            dfs2(to, v);
        }
    }
    if (v == 1)
        return;
    for (int i = 19; i >= 0; i--) {
        say[v][i] = min(say[v][i], say[v][i+1]);
        if (i > 0) {
            say[up[v][0]][i-1] = min(say[up[v][0]][i-1], say[v][i]);
            say[up[v][i-1]][i-1] = min(say[up[v][i-1]][i-1], say[v][i]);
        }
    }
    if (say[v][0] == MOD) {
        cout << -1 << endl;
        exit(0);
    }
    sum += say[v][0];
}

int main() {
    //freopen("input.txt","r",stdin);
    srand(time(0));
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
        ass[i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 20; j++)
            say[i][j] = MOD;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < k; i++) {
        a[i] = read(); b[i] = read();
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
        dsu_unite(a[i], b[i]);
    }
    ll flag = 0;
    for (int i = 0; i < m; i++) {
        x = read(); y = read(); z = read();
        ll c1 = dsu_get(x);
        ll c2 = dsu_get(y);
        if (c1 == c2) {
            mag.push_back(mp(mp(x,y), z));
        } else {
            flag = 1;
            dsu_unite(x, y);
            g[x].push_back(y);
            g[y].push_back(x);
            mag.push_back(mp(mp(x,y), 0));
        }
    }
    dfs(1, 0);
    for (int i = 0; i < mag.size(); i++) {
        ll x = mag[i].X.X;
        ll y = mag[i].X.Y;
        ll z = mag[i].Y;
        ll lc = lca(x, y);
        lol(x, lvl[x] - lvl[lc], z);
        lol(y, lvl[y] - lvl[lc], z);
    }
    dfs2(1);
    cout << sum << endl;
    return 0;
}