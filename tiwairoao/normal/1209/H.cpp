#include<cstdio>
#include<algorithm>
using namespace std;
typedef double db;
const int MAXN = 200000;
const db EPS = 1E-7;
const db INF = 1E10;
struct segtree{
	#define lch (x<<1)
	#define rch (x<<1|1)
	struct node{
		int l, r;
		db tg, mn;
	}t[8*MAXN + 5];
	void build(int x, int l, int r) {
		t[x].l = l, t[x].r = r, t[x].mn = 0;
		if( l == r ) return ;
		int mid = (l + r) >> 1;
		build(lch, l, mid), build(rch, mid + 1, r);
	}
	void pushup(int x) {
		t[x].mn = min(t[lch].mn, t[rch].mn);
	}
	void pushdown(int x) {
		if( t[x].tg ) {
			t[lch].tg += t[x].tg, t[rch].tg += t[x].tg;
			t[lch].mn += t[x].tg, t[rch].mn += t[x].tg;
			t[x].tg = 0;
		}
	}
	void modify(int x, int l, int r, db k) {
		if( l > t[x].r || r < t[x].l )
			return ;
		if( l <= t[x].l && t[x].r <= r ) {
			t[x].tg += k, t[x].mn += k;
			return ;
		}
		pushdown(x);
		modify(lch, l, r, k);
		modify(rch, l, r, k);
		pushup(x);
	}
	db query(int x, int l, int r) {
		if( l > t[x].r || r < t[x].l )
			return INF;
		if( l <= t[x].l && t[x].r <= r )
			return t[x].mn;
		pushdown(x);
		return min(query(lch, l, r), query(rch, l, r));
	}
}T;
struct node{
	db v0, s; int id;
	friend bool operator < (node a, node b) {
		return a.v0 < b.v0;
	}
}a[2*MAXN + 5];
db e[2*MAXN + 5];
int n, L;
int main() {
	scanf("%d%d", &n, &L);
	int lst = 0, cnt = 0;
	for(int i=1;i<=n;i++) {
		int x, y; db s;
		scanf("%d%d%lf", &x, &y, &s);
		cnt++, a[cnt].id = cnt, a[cnt].v0 = 0, a[cnt].s = x - lst;
		lst = y;
		cnt++, a[cnt].id = cnt, a[cnt].v0 = s, a[cnt].s = y - x;
	}
	cnt++, a[cnt].id = cnt, a[cnt].v0 = 0, a[cnt].s = L - lst;
	sort(a + 1, a + cnt + 1); T.build(1, 1, cnt);
	for(int i=1;i<=cnt;i++)
		if( a[i].v0 ) T.modify(1, a[i].id, cnt, e[i] = a[i].s/a[i].v0);
		else e[i] = 0;
	for(int i=1;i<=cnt;i++) {
//		printf("%lf %lf %lf\n", e[i], a[i].s, a[i].v0);
	}
	for(int i=1;i<=cnt;i++) {
		db x = e[i] - (-a[i].s/(a[i].v0 + 2)), y = T.query(1, a[i].id, cnt), z = min(x, y);
//		printf("%d %lf %lf\n", i, x, y);
		T.modify(1, a[i].id, cnt, -z), e[i] -= z;
	}
	db ans = 0;
	for(int i=1;i<=cnt;i++) {
		ans += (e[i] + a[i].s) / (a[i].v0 + 1);
//		printf("%d : %lf %lf %lf\n", a[i].id, e[i], a[i].s, a[i].v0);
	}
	printf("%.10lf\n", ans);
}