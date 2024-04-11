#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 300000;
const int INF = (1<<30);
struct segtree{
	#define lch (x<<1)
	#define rch (x<<1|1)
	struct node{
		int l, r;
		int cnt, mn;
	}t[4*MAXN + 5];
	void build(int x, int l, int r) {
		t[x].l = l, t[x].r = r, t[x].cnt = 0, t[x].mn = r + 1;
		if( l == r ) return ;
		int mid = (l + r) >> 1;
		build(lch, l, mid), build(rch, mid + 1, r);
	}
	void pushup(int x) {
		t[x].cnt = t[lch].cnt + t[rch].cnt;
		if( t[lch].cnt ) t[x].mn = t[lch].mn;
		else t[x].mn = t[rch].mn;
	}
	void insert(int x, int p) {
		if( p > t[x].r || p < t[x].l )
			return ;
		if( t[x].l == t[x].r ) {
			t[x].mn = p, t[x].cnt++;
			return ;
		}
		insert(lch, p), insert(rch, p);
		pushup(x);
	}
	int query(int x, int p) {
		if( t[x].l == t[x].r )
			return t[x].l + (!t[x].cnt);
		int mid = (t[x].l + t[x].r) >> 1;
		if( p > mid ) return query(rch, p);
		else {
			int k = query(lch, p);
			if( k > mid ) return t[rch].mn;
			else return k;
		}
	}
}T;
pii b[MAXN + 5];
int a[MAXN + 5], c[MAXN + 5], n;
int nxt[MAXN + 5];
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &a[i]);
	for(int i=1;i<=n;i++)
		a[i + 2*n] = a[i + n] = a[i];
	for(int i=1;i<=3*n;i++)
		b[i] = make_pair(a[i], i);
	sort(b + 1, b + 3*n + 1);
	T.build(1, 1, 3*n);
	int p = 1;
	for(int q=1;q<=3*n;q++) {
		while( 2*b[p].first < b[q].first )
			T.insert(1, b[p++].second);
		nxt[b[q].second] = T.query(1, b[q].second);
	}
	int mn = 3*n + 1;
	for(int i=3*n;i>=1;i--) {
		mn = min(mn, nxt[i]);
		if( mn == 3*n + 1 ) c[i] = -1;
		else c[i] = mn - i;
	}
	for(int i=1;i<=n;i++)
		printf("%d ", c[i]);
}