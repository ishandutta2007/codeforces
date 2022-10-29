#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define PB push_back
typedef long long LL;
const int N = 5e5+5;
const LL INF = 1e16;

struct edge{
	int to;
	LL w;
};
vector<edge> g[N];
struct dat{
	int id, l, r;
	LL ans;
}a[N];
vector<dat> b[N];
int n, q, p, w, v, l, r;
LL d[N], tree[(1<<20)+5], lazy[(1<<20)+5];

void build(int i=1, int l=1, int r=n) {
	if(l==r) {
		tree[i]=d[l];
		return;
	}
	int m=l+r>>1;
	build(i<<1, l, m);
	build(i<<1|1, m+1, r);
	tree[i]=min(tree[i<<1],tree[i<<1|1]);
}

void app(int i, LL a, int l, int r) {
	lazy[i] = lazy[i] + a;
	tree[i] = tree[i] + a;
}

void pushdown(int i, int l, int m, int r) {
	app(i<<1, lazy[i], l, m);
	app(i<<1|1, lazy[i], m+1, r);
	lazy[i] = 0;
}

void update(int l1, int r1, LL x, int i=1, int l2=1, int r2=n) {
	if(l1<=l2&&r2<=r1) {
		app(i, x, l2, r2);
		return;
	}
	int m2=l2+r2>>1;
	pushdown(i, l2, m2, r2);
	if(l1<=m2) update(l1, r1, x, i<<1, l2, m2);
	if(m2<r1) update(l1, r1, x, i<<1|1, m2+1, r2);
	tree[i]=min(tree[i<<1],tree[i<<1|1]);
}

LL query(int l1, int r1, int i=1, int l2=1, int r2=n) {
	if(l1<=l2&&r2<=r1)
		return tree[i];
	int m2=l2+r2>>1;
	pushdown(i, l2, m2, r2);
	return min(l1<=m2 ? query(l1, r1, i<<1, l2, m2) : INF,  m2<r1 ? query(l1, r1, i<<1|1, m2+1, r2) : INF);
}

void dfs(int x, LL dis){
	d[x] = g[x].size() ? INF : dis;
	a[x].l = a[x].r = x;
	for(auto u:g[x]){
		int y = u.to;
		dfs(y, dis + u.w);
		a[x].r = max(a[x].r, a[y].r);
	}
}

void dfs1(int x){
	for(auto &xx:b[x]){
		xx.ans = query(xx.l, xx.r);
	}
	for(auto u:g[x]){
		int y = u.to;
		update(a[y].l, a[y].r, -u.w<<1);
		update(1, n, u.w);
		dfs1(y);
		update(a[y].l, a[y].r, u.w<<1);
		update(1, n, -u.w);
	}
}

int main(){
	scanf("%d%d",&n,&q);
	rep(i,2,n){
		scanf("%d%d",&p,&w);
		g[p].PB({i,w});
	}
	rep(i,1,q){
		scanf("%d%d%d",&v,&l,&r);
		b[v].PB({i,l,r,0});
	}
	dfs(1,0);
	build();
	dfs1(1);
	q = 0;
	rep(i,1,n){
		for(auto x:b[i]) a[++q] = x;
	}
	sort(a+1, a+q+1, [](dat x,dat y){return x.id<y.id;});
	rep(i,1,q){
		printf("%lld\n", a[i].ans);
	}
	return 0;
}