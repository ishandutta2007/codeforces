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

int n, m;
vector<list<int> > gr;
vector<list<pair<int, int> > > qu;
vector<int> ans;
vector<int> sz, h;
vector<int> cnt;
vector<char> big;
int L;
vector<vector<int> > up;
vector<int> maxd;

void calc(int v, int p){
	sz[v] = 1;
	h[v] = (p == v) ? 0 : (h[p] + 1);
	maxd[v] = h[v];
	up[v][0] = p;
	F(i, 1, L + 1)
		up[v][i] = up[up[v][i - 1]][i - 1];
	I(u, gr[v]){
		if(u == p)cont;
		calc(u, v);
		sz[v] += sz[u];
		maxd[v] = max(maxd[v], maxd[u]);
	}
}

int anc(int v, int k){
	Df(i, L, -1){
		if(k >= (1 << i)){v = up[v][i]; k -= (1 << i);}
	}
	ret v;
}

void add(int v, int p, int d){
	cnt[h[v]] += d;
	I(u, gr[v])
		if(u != p && !big[u])
			add(u, v, d);
}

void dfs(int v, int p, int k){
	int ms = -1, bc = -1;
	I(u, gr[v]){
		if(u != p && sz[u] > ms){ms = sz[u]; bc = u;}
	}
	I(u, gr[v]){
		if(u != p && u != bc)
			dfs(u, v, 0);
	}
	if(bc != -1)
		dfs(bc, v, 1), big[bc] = true;
	add(v, p, 1);
	I(q, qu[v]){
		int hh = h[v] + q.X;
		if(hh > maxd[v]){ans[q.Y] = 0; cont;}
		ans[q.Y] = max(0, cnt[hh] - 1);
	}
	if(bc != -1)
		big[bc] = false;
	if(k == 0)
		add(v, p, -1);
}

int main(){
//	freopen("input.txt", "r", stdin);
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
	scanf("%d", &n);
	gr.rs(n + 1); qu.rs(n + 1); sz.rs(n + 1); h.rs(n + 1);
	big.rs(n + 1); big.asg(n + 1, false); cnt.rs(n + 1); cnt.asg(n + 1, 0);
	maxd.rs(n + 1);
	F(i, 0, n){
		int p;
		scanf("%d", &p);
		p--;
		if(p == -1)
			p = n;
		gr[p].pb(i); gr[i].pb(p);
	}
	int tt = 1; L = 0;
	while(tt < (n + 1)){tt *= 2; L++;}
	up.rs(n + 1);
	F(i, 0, n + 1)
		up[i].rs(L + 1);
	calc(n, n);
	scanf("%d", &m);
	ans.rs(m);
	F(i, 0, m){
		int v, k;
		scanf("%d%d", &v, &k); v--;
		int pp = anc(v, k);
		int _p = anc(v, k - 1);
		if(pp == _p || pp == n){ans[i] = 0; cont;}
		//printf("Anc for %d is %d\n", v + 1, pp + 1);
		qu[pp].pb(mk(k, i));
	}
	dfs(n, -1, 0);
	F(i, 0, m)
		printf("%d ", ans[i]);
	ret 0;
}