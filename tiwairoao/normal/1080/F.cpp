#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100000;
const int MAXK = 300000;
const int INF = (1<<30);
struct Segment{
	int l, r, p;
	Segment(int _l=0, int _r=0, int _p=0):l(_l), r(_r), p(_p){}
}seg[MAXK + 5];
bool operator < (Segment a, Segment b) {
	return a.r < b.r;
}
struct SegmentTree{
	SegmentTree *ch[2]; int mn;
}tree[MAXK*20 + 5], *root[MAXK + 5], *NIL, *tcnt;
void init() {
	NIL = tcnt = &tree[0];
	NIL->ch[0] = NIL->ch[1] = NIL;
	NIL->mn = -INF;
}
void insert(SegmentTree *rt1, SegmentTree *&rt2, int pos, int key, int le, int ri) {
	rt2 = (++tcnt); *(rt2) = *(rt1);
	if( le == ri ) rt2->mn = max(rt2->mn, key);
	else {
		int mid = (le + ri) >> 1;
		if( pos <= mid )
			insert(rt1->ch[0], rt2->ch[0], pos, key, le, mid);
		else insert(rt1->ch[1], rt2->ch[1], pos, key, mid+1, ri);
		rt2->mn = min(rt2->ch[0]->mn, rt2->ch[1]->mn);
	}
}
int query(SegmentTree *rt, int le, int ri, int ql, int qr) {
	if( ql > ri || qr < le )
		return INF;
	else if( ql <= le && ri <= qr )
		return rt->mn;
	int mid = (le + ri) >> 1;
	return min(query(rt->ch[0], le, mid, ql, qr), query(rt->ch[1], mid+1, ri, ql, qr));
}
int main() {
	init(); int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1;i<=k;i++)
		scanf("%d%d%d", &seg[i].l, &seg[i].r, &seg[i].p);
	sort(seg+1, seg+k+1); root[0] = NIL;
	for(int i=1;i<=k;i++)
		insert(root[i-1], root[i], seg[i].p, seg[i].l, 1, n);
	for(int i=1;i<=m;i++) {
		int a, b, x, y;
		scanf("%d%d%d%d", &a, &b, &x, &y);
		int p = upper_bound(seg+1, seg+k+1, Segment(0, y, 0)) - seg - 1;
		int q = query(root[p], 1, n, a, b);
		if( q >= x ) puts("yes");
		else puts("no");
		fflush(stdout);
	}
}