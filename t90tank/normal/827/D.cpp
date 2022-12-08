#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
using pii = pair<int,int>; 
#define pb push_back
#define fir first
#define sec second

void merge(set<pii> *&a, set<pii> *&b) {
	if (a->size() < b->size()) swap(a, b); 
	for (auto i : (*b)) {
		if (a->find(i) == a->end()) a->insert(i); 
		else a->erase(i); 
	}
	b->clear(); 
}

const int maxn = 200006; 
const int D = 20; 

int n, m; 
int a[maxn], b[maxn], c[maxn]; 
int f[maxn]; 
int no[maxn]; 
vector<pii> e[maxn]; 
int ans[maxn]; 
int fe[maxn]; 
set<pii> *q[maxn]; 
set<pii> sq[maxn]; 
bool intree[maxn]; 
int fa[D][maxn]; 
int val[D][maxn]; 
int d[maxn]; 

bool cmp(int x, int y) {
	return c[x] < c[y]; 
}
int getf(int v) {
	if (f[v] == v) return v; 
	f[v] = getf(f[v]); 
	return f[v]; 
}
int ask(int x, int y) {
	int ret = 0; 
	if (d[x] < d[y]) swap(x, y); 
	for (int i = D-1; i >= 0; --i) 
		if (d[x]-(1<<i) >= d[y]) {
			ret = max(ret, val[i][x]); 
			x = fa[i][x]; 
		}
	if (x==y) return ret; 
	for (int i = D-1; i >= 0; --i) 
		if (fa[i][x] != fa[i][y]) {
			ret = max(ret, max(val[i][x], val[i][y])); 
			x = fa[i][x]; 
			y = fa[i][y]; 
		}
	ret = max(ret, max(val[0][x], val[0][y])); 
	return ret; 
}
void build(int x, int f) {
	d[x] = d[f]+1; 
	fa[0][x] = f; 
	if (x != 1) val[0][x] = c[fe[x]]; 
	for (int i = 1; i < D; ++i) {
		fa[i][x] = fa[i-1][fa[i-1][x]]; 
		val[i][x] = max(val[i-1][x], val[i-1][fa[i-1][x]]); 
	}
	for (auto i : e[x]) 
		if (i.fir != f) {
			fe[i.fir] = i.sec; 
			build(i.fir, x); 
		}
}

void dfs(int x, int f) {
	for (auto i : e[x]) 
		if (i.fir != f) {
			dfs(i.fir, x); 
			merge(q[x], q[i.fir]);  
		}
	//cout<<x<<' '<<fe[x]<<' '<<q[x]->size()<<endl; 
	if (!q[x]->empty()) 
		ans[fe[x]] = (q[x]->begin())->fir-1; 
	else ans[fe[x]] = -1; 
}

int main() {
	scanf( "%d%d", &n, &m ); 
	for (int i = 1; i <= m; ++i) {
		scanf( "%d%d%d", &a[i], &b[i], &c[i] ); 
		no[i] = i; 
	}
	sort(no+1, no+m+1, cmp); 
	for (int i = 1; i <= n; ++i) f[i] = i; 
	for (int i = 1; i <= m; ++i) {
		int x = a[no[i]], y = b[no[i]]; 
		int fx = getf(x), fy = getf(y); 
		if (fx != fy) {
			e[x].pb( {y, no[i]} ); 
			e[y].pb( {x, no[i]} ); 
			f[fx] = fy; 
			intree[no[i]] = true; 
			//cout<<x<<' '<<y<<endl; 
		}
		else {
			sq[x].insert({c[no[i]], no[i]}); 
			sq[y].insert({c[no[i]], no[i]}); 
		}
	}
	for (int i = 1; i <= n; ++i) q[i] = &sq[i]; 
	build(1, 0); 
	dfs(1, 0); 
	for (int i = 1; i <= m; ++i) 
		if (!intree[i]) 
			ans[i] = ask(a[i], b[i])-1; 
	for (int i = 1; i <= m; ++i) printf( "%d ", ans[i] ); 
	puts( "" ); 
}