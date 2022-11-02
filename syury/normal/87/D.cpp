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

const int MAXN = 1e5 + 5;

struct edge{
	int v, u;
	int w;
	int id;
	lint cnt = 0ll;
};

auto comp = [](const edge & a, const edge & b){
	ret a.w < b.w;
};

int p[MAXN];
int sz[MAXN];
int tsz[MAXN];
bool used[MAXN];
int root[MAXN];
int n;
edge e[MAXN];
vector<int> gr[MAXN];
set<int> kek;

int find_set(int v){
	ret (v == p[v]) ? v : p[v] = find_set(p[v]);
}

void unite(int v, int u){
	v = find_set(p[v]);
	u = find_set(p[u]);
	if(v == u)ret;
	if(sz[v] > sz[u])swap(v, u);
	p[v] = u;
	sz[u] += sz[v];
}

int sum;

void dfs(int v, int pr, int rt){
	tsz[v] = sz[v];
	used[v] = true;
	root[v] = rt;
	I(u, gr[v]){
		if(u == pr)cont;
		dfs(u, v, rt);
		tsz[v] += tsz[u];
	}
}

void solve(int l, int r){
	sum = 0;
	kek.clear();
	F(i, l, r + 1){
		int v = find_set(e[i].v);
		int u = find_set(e[i].u);
		tsz[v] = tsz[u] = 0;
		used[v] = used[u] = false;
		gr[v].pb(u); gr[u].pb(v);
		if(!kek.count(v)){kek.ins(v);}
		if(!kek.count(u)){kek.ins(u);}
	}
	I(v, kek){
		if(!used[v])dfs(v, -1, v);
	}
	F(i, l, r + 1){
		int v = find_set(e[i].v);
		int u = find_set(e[i].u);
		if(tsz[v] > tsz[u])swap(v, u);
		e[i].cnt = 2 * tsz[v] * 1ll * (tsz[root[v]] - tsz[v]);
		gr[v].clear(); gr[u].clear();
	}
	F(i, l, r + 1)unite(find_set(e[i].v), find_set(e[i].u));
}

set<int> lol;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	fi0(tsz);
	scanf("%d", &n);
	F(i, 0, n){p[i] = i; sz[i] = 1;}
	F(i, 0, n - 1){
		scanf("%d%d%d", &e[i].v, &e[i].u, &e[i].w);
		e[i].v--; e[i].u--; e[i].id = i;
	}
	sort(e, e + n - 1, comp);
	int l = 0;
	F(i, 0, n - 1){
		if(i < n - 2 && e[i].w == e[i + 1].w)cont;
		solve(l, i);
		l = i + 1;
	}
	lint best = -1;
	F(i, 0, n - 1){
		if(e[i].cnt > best){best = e[i].cnt; lol.clear();}
		if(e[i].cnt == best)lol.ins(e[i].id);
	}
	printf("%lld %d\n", best, (int)lol.size());
	I(v, lol)printf("%d ", v + 1);
	ret 0;
}