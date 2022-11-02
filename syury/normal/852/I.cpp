#include <bits/stdc++.h>

using namespace std;

#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define ins insert
#define X first
#define Y second
#define fin(name) freopen(name, "r", stdin)
#define fout(name) freopen(name, "w", stdout)
#define files(name) fin(name".in"); fout(name".out")
#define fi(st,n) for (int i = (st); i <= (int)(n); ++i)
#define fj(st,n) for (int j = (st); j <= (int)(n); ++j)
#define fk(st,n) for (int k = (st); k <= (int)(n); ++k)
#define fq(st,n) for (int q = (st); q <= (int)(n); ++q)
#define fw(st,n) for (int w = (st); w <= (int)(n); ++w)
#define ff(i, st, n) for (int (i) = (st); (i) <= (int)(n); ++(i))
#define ei(st,n) for (int i = (st); i >= (int)(n); --i)
#define ej(st,n) for (int j = (st); j >= (int)(n); --j)
#define ek(st,n) for (int k = (st); k >= (int)(n); --k)
#define ef(i, st, n) for (int (i) = (st); (i) >= (int)(n); --(i))
#define ri(st,n) for (int i = (st); i < (int)(n); ++i)
#define rj(st,n) for (int j = (st); j < (int)(n); ++j)
#define rk(st,n) for (int k = (st); k < (int)(n); ++k)
#define rq(st,n) for (int q = (st); q < (int)(n); ++q)
#define rf(i, st, n) for (int (i) = (st); (i) < (int)(n); ++(i))
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define y1 dsklmlvmd

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const dbl eps = (dbl) 1e-8;
const int mod = (int) 1e9 + 7;
const int maxn = (int) 1e5 + 5;
const int MX = (int) 1e5;
//const dbl M_PI = (dbl)2 * (dbl)acos(0);

//cout<<fixed<<setprecision(15);
//srand(time(0));


int n, m;
int t[maxn];
vector <int> a[maxn];
map <int, int> mz;
int to_clean[maxn], to_cnt;
pair <int, int> path[maxn];
vector <int> vp[maxn], vd[maxn];
int tim, tin[maxn], tout[maxn], kg[maxn], kb[maxn], f[maxn], sex[maxn], p[maxn], calc_now[maxn], h[maxn];
ll o, ans[maxn];
int root, SQ;
int k[maxn];

void add(int v, ll& o)
{
	int x = f[v];
	if (sex[v] == 1)
	{
		o += kg[x];
		++kb[x];
	}
	else
	{
		o += kb[x];
		++kg[x];
	}
}
void del(int v, ll& o)
{
	int x = f[v];
	if (sex[v] == 1)
	{
		--kb[x];
		o -= kg[x];
	}
	else
	{
		--kg[x];
		o -= kb[x];
	}
}


void stupid_sol(int z)
{
	int v = path[z].X, u = path[z].Y;
	ll o = 0;
	to_cnt = 0;
//	cout << "goal = " << tin[u] << " " << tout[u] << endl;
	while (!(tin[v] <= tin[u] && tout[v] >= tout[u]))
	{
//		cout << v << " " << tin[v] << " " << tout[v] << endl;
//		if (v == 0)
//			exit(0);
		int x = f[v];
		add(v, o);
//		cout << v << " " << o << endl;
		to_clean[++to_cnt] = x;
		v = p[v];
	}
//	exit(0);
	while (1)
	{
		int x = f[u];
		add(u, o);
//		cout << u << " " << o << endl;
		to_clean[++to_cnt] = x;
		if (u == v)
			break;
		u = p[u];
	}
//	cout << kg[0] << " " << kb[0] << endl; 
	ans[z] = o;
	if (to_cnt > 3 * SQ + 10)
		exit(123);
//	exit(0);
	fi(1, to_cnt)
	{
		int x = to_clean[i];
		kg[x] = 0;
		kb[x] = 0;	
	}
}

void dfs0(int v, int pr)
{
	p[v] = pr;
	tin[v] = ++tim;
	ri(0, a[v].size())
	{
		if (a[v][i] == pr)
			continue;
		dfs0(a[v][i], v);
	}
	tout[v] = tim;
}

void dfs1(int v)
{
	if (t[v])
		return;
	ri(0, vp[v].size())
	{
		int x = vp[v][i];
		if (ans[x] == -1)
		{
			calc_now[x] = 1;
			int u = path[x].X;
			if (u == v)
				u = path[x].Y;
			vd[u][k[u]] = x;
			++k[u];
		}
	}
	t[v] = 1;
	ri(0, a[v].size())
	{
		int to = a[v][i];
		if (to != p[v])
			dfs1(to);
	}
}

void dfs2(int v, int pr = 0)
{
	if (t[v])
		return;
	add(v, o);

	if (v != root)
	{
		ri(0, k[v])
		{
			int x = vd[v][i];
			if (!calc_now[x] || ans[x] != -1)
				continue;
			int u = path[x].X;
			if (u == v)
				u = path[x].Y;
			int w = u;
			while (w != root)
			{
				add(w, o);
				w = p[w];
			}
			ans[x] = o;
			w = u;
			while (w != root)
			{
				del(w, o);
				w = p[w];
			}
		}
	}
	k[v] = 0;

	ri(0, a[v].size())
	{
		int to = a[v][i];
		if (to == pr)
			continue;
		dfs2(to, v);
	}

	del(v, o);
}


void dfs(int v)
{
	if (t[v])
	{
		h[v] = 0;
		return;
	}
	h[v] = 1;
	ri(0, a[v].size())
	{
		if (a[v][i] == p[v])
			continue;
		dfs(a[v][i]);
		h[v] = max(h[v], h[a[v][i]] + 1);
	}
}


void solve()
{
	root = 0;
	dfs(1);
	fi(1, n)
	{
		if (!t[i] && h[i] <= SQ && (root == 0 || h[root] < h[i]))
			root = i;
	}
	if (root == 0)
		return;

	dfs1(root);

	o = 0;
	t[root] = 0;
	dfs2(root);
	t[root] = 1;

	solve();
}

int main()
{
//    fin("t.in");
    sync;
    cin >> n;
    SQ = 800;
    fi(1, n)
    {
    	cin >> sex[i];
    }
    fi(1, n)
    {
    	cin >> f[i];
    	if (mz.count(f[i]) == 0)
    	{
    		int x = mz.size();
    		mz[f[i]] = x;
    		f[i] = x;
    	}
    	else
    		f[i] = mz[f[i]];
    }
    fi(1, n - 1)
    {
    	int x, y;
    	cin >> x >> y;
    	a[x].pb(y);
    	a[y].pb(x);
    }
    tim = 0;
    dfs0(1, 0);
    cin >> m;
    fi(1, m)
    {
    	cin >> path[i].X >> path[i].Y;
    	vp[path[i].X].pb(i);
    	vp[path[i].Y].pb(i);

    	vd[path[i].X].pb(0);
    	vd[path[i].Y].pb(0);

    	ans[i] = -1;
    }
    clean(t);
    clean(calc_now);
    clean(k);

    solve();
//    return 0;
    fi(1, m)
    {
    	if (ans[i] == -1)
    	{
//    		cout << i << endl;
    		stupid_sol(i);
    	}
    	cout << ans[i] << "\n";
    }

    return 0;
}