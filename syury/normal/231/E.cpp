#include<bits/stdc++.h>

using namespace std;

using namespace std;
typedef long long int ll;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define DF(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mp make_pair
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
const int mod = 1000000007;

int n, m;
vector<int> gr[MAXN];
vector<int> g[MAXN];
bool small[MAXN];
int cycle[MAXN];
int cid = 0, gt = 0;
int col[MAXN];
int p[MAXN];
int pw[MAXN];
int sum[MAXN];
int tin[MAXN], tout[MAXN];
int up[MAXN][20];

void mark(int v, int start){
	//printf("marking %d as %d with start = %d\n", v, cid, start);
	cycle[v] = cid;
	if(v == start)ret;
	mark(p[v], start);
}

void build(int v){
	col[v] = 1;
	I(u, gr[v]){
		if(u == p[v])cont;
		if(col[u] == 2)cont;
		if(col[u] == 1){mark(v, u); cid++; cont;}
		p[u] = v;
		build(u);
	}
	col[v] = 2;
}

void dfs(int v, int pr = -1){
	sum[v] = (pr == -1) ? 0 : sum[pr];
	if(!small[v])sum[v]++;
	if(pr == -1)pr = v;
	tin[v] = gt++;
	up[v][0] = pr;
	F(i, 1, 20)up[v][i] = up[up[v][i - 1]][i - 1];
	I(u, g[v]){
		if(u != pr)dfs(u, v);
	}
	tout[v] = gt++;
}

bool ispr(int v, int u){
	ret (tin[v] <= tin[u]) && (tout[v] >= tout[u]);
}

int lca(int v, int u){
	if(ispr(v, u))ret v;
	if(ispr(u, v))ret u;
	DF(i, 19, -1)if(!ispr(up[v][i], u))v = up[v][i];
	ret up[v][0];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &n, &m);
	F(i, 0, m){
		int v, u;
		scanf("%d%d", &v, &u);
		v--; u--;
		gr[v].pb(u); gr[u].pb(v);
	}
	F(i, 0, n)cycle[i] = -1;
	p[0] = -1;
	build(0);
	F(i, 0, n)if(cycle[i] == -1){small[cid] = true; cycle[i] = cid++;}
	//F(i, 0, n)printf("%d in cycle %d\n", i, cycle[i]);
	pw[0] = 1;
	F(i, 1, n + 1)pw[i] = pw[i - 1] * 2 % mod;
	F(i, 0, n)I(j, gr[i])if(cycle[i] != cycle[j])g[cycle[i]].pb(cycle[j]);
	dfs(0);
	int q;
	scanf("%d", &q);
	F(i, 0, q){
		int v, u;
		scanf("%d%d", &v, &u);
		v--; u--;
		v = cycle[v]; u = cycle[u];
		int w = lca(v, u);
		int cnt = sum[v] + sum[u] - 2 * sum[w] + (!small[w] ? 1 : 0);
		printf("%d\n", pw[cnt]);
	}
	return 0;
}