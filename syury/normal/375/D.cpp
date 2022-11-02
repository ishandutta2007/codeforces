#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define y1 adjf
#define tm dhgdg

const int MAXN = 1e5 + 5;

int n, m;
int cnt[MAXN];
int t[MAXN];
int c[MAXN];
int sz[MAXN];
int ans[MAXN];
bool big[MAXN];
vector<int> gr[MAXN];
vector<pair<int, int> > q[MAXN];

void upd(int x, int d){
	for(; x < MAXN; x = (x|(x + 1)))t[x] += d;
}

int get(int x){
	int res = 0;
	for(; x >= 0; x = (x&(x + 1)) - 1)res += t[x];
	ret res;
}

void add(int v, int p, int d){
	upd(cnt[c[v]], -1);
	cnt[c[v]] += d;
	upd(cnt[c[v]], 1);
	I(u, gr[v])
		if(u != p && !big[u])add(u, v, d);
}

void dfs(int v, int p, bool keep){
	int ms = 0, mc = -1;
	I(u, gr[v]){
		if(u == p)cont;
		if(sz[u] > ms){ms = sz[u]; mc = u;}
	}
	I(u, gr[v])
		if(u != p && u != mc)dfs(u, v, 0);
	if(mc != -1){
		big[mc] = true;
		dfs(mc, v, 1);
	}
	add(v, p, 1);
	I(j, q[v]){
		int k = j.X, id = j.Y;
		ans[id] = n - get(k - 1);
	}
	if(mc != -1)big[mc] = 0;
	if(!keep)add(v, p, -1);
}

void calc(int v, int p = -1){
	sz[v] = 1;
	I(u, gr[v])
		if(u != p)
			calc(u, v), sz[v] += sz[u];
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &n, &m);
	F(i, 0, n)scanf("%d", &c[i]);
	F(i, 0, n - 1){
		int v, u;
		scanf("%d%d", &v, &u); v--; u--;
		gr[v].pb(u);
		gr[u].pb(v);
	}
	fi0(ans); fi0(cnt); fi0(t);
	upd(0, n);
	F(i, 0, m){
		int v, k;
		scanf("%d%d", &v, &k); v--;
		q[v].pb(mk(k, i));
	}
	calc(0);
	dfs(0, -1, 0);
	F(i, 0, m)printf("%d\n", ans[i]);
	ret 0;
}