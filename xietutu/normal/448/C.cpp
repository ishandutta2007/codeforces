#include <cstdio>
#include <algorithm>
const int maxn = 5005;
int n,st,ed;
struct arr {
	int v,no;
	arr(int _v = 0,int _no = 0):v(_v),no(_no) {}
} seg[maxn * 4];
bool operator<(const arr& lhs,const arr& rhs) {
	return lhs.v < rhs.v;
}
int a[maxn];
void build(int tot,int l,int r) {
	if (l == r) {
		seg[tot] = arr(a[l],l);
		return;
	}
	int mid = (l + r) / 2;
	build(tot * 2,l,mid);
	build(tot * 2 + 1,mid + 1,r);
	if (seg[tot * 2] < seg[tot * 2 + 1]) 
		seg[tot] = seg[tot * 2];
	else seg[tot] = seg[tot * 2 + 1]; 
}
arr query(int tot,int l,int r) {
	if (st <= l && r <= ed) return seg[tot];
	int mid = (l + r) / 2;
	if (ed <= mid) return query(tot * 2,l,mid);
	if (st > mid) return query(tot * 2 + 1,mid + 1,r);
	arr a = query(tot * 2,l,mid),b = query(tot * 2 + 1,mid + 1,r);
	if (a < b) return a;
	else return b;
}
int calc(int l,int r,int h) {
	if (l > r) return 0;
	st = l; ed = r;
	arr m = query(1,1,n);
	return std::min(r - l + 1,calc(l,m.no-1,m.v) + calc(m.no + 1,r,m.v) + m.v - h);
}
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) scanf("%d",a + i);
	build(1,1,n);
	printf("%d",calc(1,n,0));
	fclose(stdin); fclose(stdout);
}