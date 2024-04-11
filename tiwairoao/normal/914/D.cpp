#include<cstdio>
const int MAXN = 500000;
struct node{
	int le, ri;
	int gcd;
}tree[3*MAXN + 5];
int a[MAXN + 5];
int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x%y);
}
void PushUp(int x) {
	tree[x].gcd = gcd(tree[x<<1].gcd, tree[x<<1|1].gcd);
}
void Build(int x, int l, int r) {
	tree[x].le = l, tree[x].ri = r;
	if( l == r ) {
		tree[x].gcd = a[l];
		return ;
	}
	int mid = (l + r) >> 1;
	Build(x<<1, l, mid);
	Build(x<<1|1, mid+1, r);
	PushUp(x);
}
void Modify(int x, int i, int y) {
	if( i > tree[x].ri || i < tree[x].le )
		return ;
	if( tree[x].le == tree[x].ri ) {
		tree[x].gcd = y;
		return ;
	}
	Modify(x<<1, i, y);
	Modify(x<<1|1, i, y);
	PushUp(x);
}
bool Query1(int x, int l, int r, int k) {
	if( l <= tree[x].le && tree[x].ri <= r ) {
		if( tree[x].gcd % k == 0 ) return true;
		else return false;
	}
	if( l > tree[x].ri || r < tree[x].le )
		return true;
	return Query1(x<<1, l, r, k) && Query1(x<<1|1, l, r, k);
}
bool Query2(int x, int l, int r, int k) {
	if( l > tree[x].ri || r < tree[x].le )
		return true;
	if( l <= tree[x].le && tree[x].ri <= r ) {
		if( tree[x].gcd % k == 0 ) return true;
		else if( tree[x].le == tree[x].ri ) return true;
		else {
			if( tree[x<<1].gcd % k == 0 ) return Query2(x<<1|1, l, r, k);
			else if( tree[x<<1|1].gcd % k == 0 ) return Query2(x<<1, l, r, k);
			else return false;
		}
	}
	bool p1 = Query1(x<<1, l, r, k), p2 = Query1(x<<1|1, l, r, k);
	if( p1 ) return Query2(x<<1|1, l, r, k);
	else if( p2 ) return Query2(x<<1, l, r, k);
	else return false;
}
int main() {
	int n, q;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &a[i]);
	Build(1, 1, n);
	scanf("%d", &q);
	for(int i=1;i<=q;i++) {
		int cmd;
		scanf("%d", &cmd);
		if( cmd == 1 ) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			puts(Query2(1, l, r, x) ? "YES" : "NO");
		}
		else {
			int x, y;
			scanf("%d%d", &x, &y);
			Modify(1, x, y);
		}
	}
}