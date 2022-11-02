#include<map>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 100000;
struct edge{
	int to, dis;
	edge *nxt;
}edges[2*MAXN + 5], *adj[MAXN + 5], *ecnt;
void addedge(int u, int v, int w) {
	edge *p = (++ecnt);
	p->to = u, p->dis = w;
	p->nxt = adj[v], adj[v] = p;
	p = (++ecnt);
	p->to = v, p->dis = w;
	p->nxt = adj[u], adj[u] = p;
}
bool vis[MAXN + 5];
int n, siz[MAXN + 5], blc[MAXN + 5];
ll pw[MAXN + 5], inv[MAXN + 5], M;
void exgcd(ll a, ll b, ll &x, ll &y) {
	if( b == 0 ) {
		x = 1, y = 0;
		return ;
	}
	ll x1, y1;
	exgcd(b, a%b, x1, y1);
	x = y1, y = x1 - a/b*y1;
}
void Init() {
	ecnt = &edges[0];
	for(int i=1;i<=MAXN;i++)
		adj[i] = NULL;
	blc[0] = MAXN + 5;
	pw[0] = 1;
	for(int i=1;i<=MAXN;i++)
		pw[i] = pw[i-1] * 10 % M;
	ll r; exgcd(pw[MAXN], M, inv[MAXN], r);
	inv[MAXN] = (inv[MAXN] % M + M) % M;
	for(int i=MAXN-1;i>=0;i--)
		inv[i] = inv[i+1] * 10 % M;
}
int GetG(int rt, int pre, int tot) {
	int ret = 0;
	siz[rt] = 1, blc[rt] = 0;
	for(edge *p=adj[rt];p!=NULL;p=p->nxt) {
		if( p->to == pre || vis[p->to] ) continue;
		int q = GetG(p->to, rt, tot);
		if( blc[q] < blc[ret] )
			ret = q;
		siz[rt] += siz[p->to];
		blc[rt] = max(blc[rt], siz[p->to]);
	}
	blc[rt] = max(blc[rt], tot-siz[rt]);
	if( blc[rt] < blc[ret] ) return rt;
	else return ret;
}
map<ll, ll>cnt;
void Merge(int rt, int pre, ll dis, int dep) {
	cnt[dis]++;
	for(edge *p=adj[rt];p!=NULL;p=p->nxt) {
		if( p->to == pre || vis[p->to] ) continue;
		Merge(p->to, rt, (dis + p->dis*pw[dep])%M, dep+1);
	}
}
ll Conquer(int rt, int pre, ll dis, int dep) {
	ll ret = cnt[(M-dis)*inv[dep]%M];
	for(edge *p=adj[rt];p!=NULL;p=p->nxt) {
		if( p->to == pre || vis[p->to] ) continue;
		ret += Conquer(p->to, rt, (dis*10 + p->dis)%M, dep+1);
	}
	return ret;
}
ll Divide(int rt) {
	vis[rt] = true;
	cnt.clear(); Merge(rt, -1, 0, 0);
	ll ret = Conquer(rt, -1, 0, 0) - 1;
	for(edge *p=adj[rt];p!=NULL;p=p->nxt) {
		if( vis[p->to] ) continue;
		cnt.clear(); Merge(p->to, -1, p->dis, 1);
		ret -= Conquer(p->to, -1, p->dis, 1);
		ret += Divide(GetG(p->to, -1, siz[p->to]));	
	}
	return ret;
}
int main() {
	scanf("%d%I64d", &n, &M);
	Init();
	for(int i=1;i<n;i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		addedge(u+1, v+1, w%M);
	}
	printf("%I64d\n", Divide(GetG(1, -1, n)));
}