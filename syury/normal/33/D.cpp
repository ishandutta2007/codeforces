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
#define acpy(y, x) memcpy(y, x, sizeof(y))
#define y1 adjf
#define tm dhgdg

const int MAXN = 1e3 + 3;
const int LOG = 12;

int n, m, k;
pair<int, int> a[MAXN];
pair<int, int> b[MAXN];
int r[MAXN];
int level[MAXN];
int stk[MAXN];
int in[MAXN];
int p[MAXN];
vector<int> gr[MAXN];
int edge[MAXN][MAXN];
int qu[MAXN + MAXN];
int qt = 0, qh = 0;
int up[MAXN][LOG];
int h[MAXN];
int tin[MAXN], tout[MAXN];
int gt = 0;
int ptr = 0;

bool inside(int i, int j){
	if(r[i] >= r[j])ret false;
	lint dist = (b[i].X - b[j].X) * 1ll * (b[i].X - b[j].X) + (b[i].Y - b[j].Y) * 1ll * (b[i].Y - b[j].Y);
	ret dist <= r[j] * 1ll * r[j];
}

bool inside(pair<int, int> pt, int i){
	lint dist = (pt.X - b[i].X) * 1ll * (pt.X - b[i].X) + (pt.Y - b[i].Y) * 1ll * (pt.Y - b[i].Y);
	ret dist <= r[i] * 1ll * r[i];
}

void dfs(int v, int pr = -1){
	tin[v] = gt++;
	h[v] = (pr == -1) ? 0 : (h[pr] + 1);
	up[v][0] = (pr == -1) ? v : pr;
	F(i, 1, LOG)up[v][i] = up[up[v][i - 1]][i - 1];
	I(u, gr[v])if(u != pr)dfs(u, v);
	tout[v] = gt++;
}

bool ispr(int v, int u){
	ret tin[v] <= tin[u] && tout[v] >= tout[u];
}

int lca(int v, int u){
	if(ispr(v, u))ret v;
	if(ispr(u, v))ret u;
	Df(i, LOG - 1, -1)if(!ispr(up[v][i], u))v = up[v][i];
	ret up[v][0];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	fi0(edge); fi0(in);
	scanf("%d%d%d", &n, &m, &k);
	F(i, 0, n)scanf("%d%d", &a[i].X, &a[i].Y);
	F(i, 0, m)scanf("%d%d%d", &r[i], &b[i].X, &b[i].Y);
	F(i, 0, m)level[i] = -1;
	F(i, 0, m){
		F(j, 0, m){
			if(j != i && inside(i, j)){in[i]++;}
		}
		if(in[i] == 0){level[i] = 0; qu[qt++] = i; p[i] = m;}
	}
	while(qh < qt){
		int i = qu[qh++];
		F(j, 0, m){
			if(j != i && level[j] == -1 && inside(j, i))
			{in[j]--; if(in[j] == 0){level[j] = level[i] + 1; p[j] = i; qu[qt++] = j;}}
		}
	}
	F(i, 0, m){gr[p[i]].pb(i); gr[i].pb(p[i]);}
	dfs(m);
	F(i, 0, k){
		int l, r;
		scanf("%d%d", &l, &r); l--; r--;
		int v = m, u = m;
		int lv = -1, lu = -1;
		F(j, 0, m){
			if(inside(a[l], j) && level[j] > lv){v = j; lv = level[j];}
			if(inside(a[r], j) && level[j] > lu){u = j; lu = level[j];}
		}
		int w = lca(v, u);
		printf("%d\n", h[v] + h[u] - 2 * h[w]);
	}
	ret 0;
}