#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 100000;
const int INF = 2*int(1E9) + 5;
struct node2{
	node2 *ch[2];
	ll sum;
}tr[160*MAXN + 5], *rot, *tcnt, *NIL;
node2 *tree[10020 + 5];
ll U = INF, D = -INF, L = INF, R = -INF;
inline ll lowbit(ll x) {
	return x & -x;
}
void Init() {
	rot = tcnt = NIL = &tr[0];
	NIL->ch[0] = NIL->ch[1] = NIL;
	NIL->sum = 0;
	for(int i=1;i<=MAXN;i++)
		tree[i] = NIL;
}
node2 *NewNode() {
	tcnt++;
	tcnt->ch[0] = tcnt->ch[1] = NIL;
	tcnt->sum = 0;
	return tcnt;
}
ll qu, qd, ql, qr;
ll Query2(node2 *rt, ll l, ll r) {
	if( rt == NIL || ql > r || qr < l )
		return 0;
	if( ql <= l && r <= qr )
		return rt->sum;
	ll mid = (l + r) >> 1;
	return Query2(rt->ch[0], l, mid) + Query2(rt->ch[1], mid+1, r);
}
ll Query1(ll x) {
	ll ret = 0;
	for(ll i=x;i;i-=lowbit(i))
		ret += Query2(tree[i], L, R);
	return ret;
}
ll x, y;
void Update2(node2 *(&rt), ll l, ll r) {
	if( y < l || y > r )
		return ;
	if( rt == NIL )
		rt = NewNode();
	rt->sum++;
	if( l == r ) return ;
	ll mid = (l + r) >> 1;
	Update2(rt->ch[0], l, mid);
	Update2(rt->ch[1], mid+1, r);
}
void Update1(ll x) {
	for(ll i=x;i<=D;i+=lowbit(i))
		Update2(tree[i], L, R);
}
struct node{
	ll x, r, f;
}a[MAXN + 5];
bool operator < (node a, node b) {
	return a.r < b.r;
}
int main() {
//	freopen("out.txt", "r", stdin);
	Init(); int n, k;
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++) {
		scanf("%I64d%I64d%I64d", &a[i].x, &a[i].r, &a[i].f);
		U = min(U, a[i].f-k+k); L = min(L, a[i].x-a[i].r);
		D = max(D, a[i].f+k+k); R = max(R, a[i].x+a[i].r);
	}
	sort(a+1, a+n+1); ll ans = 0;
	for(int i=n;i>=1;i--) {
		qu = a[i].f-k+k, qd = a[i].f+k+k, ql = a[i].x-a[i].r, qr = a[i].x+a[i].r;
		ans += Query1(qd) - Query1(qu-1);
		x = a[i].f+k, y = a[i].x;
		Update1(x);
	}
	printf("%I64d\n", ans);
}
/*
Let ri < rj.
xi + ri >= xj >= xi - ri
fi + k >= fj >= fi - k
(xi, fi)
*/