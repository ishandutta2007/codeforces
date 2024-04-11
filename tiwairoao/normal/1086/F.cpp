#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 50;
const int MOD = 998244353;
int pow_mod(int b, int p) {
	int ret = 1;
	while( p ) {
		if( p & 1 ) ret = 1LL*ret*b%MOD;
		b = 1LL*b*b%MOD;
		p >>= 1;
	}
	return ret;
}
inline int add(int a, int b) {return (a + b)%MOD;}
inline int mul(int a, int b) {return 1LL*a*b%MOD;}
inline int sub(int a, int b) {return add(a, (MOD - b)%MOD);}
inline int inv(int x) {return pow_mod(x, MOD - 2);}
vector<int>v1[2*MAXN + 5], v2[2*MAXN + 5];
int x[MAXN + 5], y[MAXN + 5], n;
int dx[2*MAXN + 5], dy[2*MAXN + 5], xcnt, ycnt;
int tag[2*MAXN + 5];
int func(int t) {
	xcnt = ycnt = 0;
	for(int i=1;i<=n;i++) {
		dx[++xcnt] = x[i] + t + 1, dx[++xcnt] = x[i] - t;
		dy[++ycnt] = y[i] + t + 1, dy[++ycnt] = y[i] - t;
	}
	sort(dx + 1, dx + xcnt + 1), xcnt = unique(dx + 1, dx + xcnt + 1) - dx - 1;
	sort(dy + 1, dy + ycnt + 1), ycnt = unique(dy + 1, dy + ycnt + 1) - dy - 1;
	for(int i=1;i<=xcnt;i++) v1[i].clear(), v2[i].clear();
	for(int i=1;i<=n;i++) {
		int l = lower_bound(dx + 1, dx + xcnt + 1, x[i] - t) - dx;
		int r = lower_bound(dx + 1, dx + xcnt + 1, x[i] + t + 1) - dx;
		v1[l].push_back(i), v2[r].push_back(i);
	}
	int ans = 0;
	for(int i=1;i<=xcnt;i++) {
		int tmp = 0;
		for(int j=1;j<=ycnt;j++) {
			if( tmp ) ans = add(ans, mul(dy[j] - dy[j-1], dx[i] - dx[i-1]));
			tmp += tag[j];
		}
		for(int j=0;j<v1[i].size();j++) {
			int p = v1[i][j];
			int u = lower_bound(dy + 1, dy + ycnt + 1, y[p] - t) - dy;
			int d = lower_bound(dy + 1, dy + ycnt + 1, y[p] + t + 1) - dy;
			tag[u]++, tag[d]--;
		}
		for(int j=0;j<v2[i].size();j++) {
			int p = v2[i][j];
			int u = lower_bound(dy + 1, dy + ycnt + 1, y[p] - t) - dy;
			int d = lower_bound(dy + 1, dy + ycnt + 1, y[p] + t + 1) - dy;
			tag[u]--, tag[d]++;
		}
	}
	return ans;
}
struct point{
	int x, y;
	point(int _x=0, int _y=0):x(_x), y(_y) {}
};
int func3(point *p, int x) {
	int ret = 0;
	for(int i=0;i<4;i++) {
		int del = 1;
		for(int j=0;j<4;j++)
			if( i != j ) del = mul(del, mul(sub(x, p[j].x), inv(sub(p[i].x, p[j].x))));
		ret = add(ret, mul(del, p[i].y));
	}
	return ret;
}
int func2(int l, int r) {
	if( r - l + 1 <= 3 ) {
		int ret = 0;
		for(int i=l;i<=r;i++) ret = add(ret, func(i));
		return ret;
	}
	point p[4] = {point(l, func(l))};
	for(int i=1;i<4;i++)
		p[i] = point(l + i, add(p[i - 1].y, func(l + i)));
	return (sub(func3(p, r), func3(p, l - 1)) + MOD)%MOD;
}
int a[MAXN*MAXN + 5], cnt;
int main() {
	int t; scanf("%d%d", &n, &t);
	for(int i=1;i<=n;i++)
		scanf("%d%d", &x[i], &y[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) {
			int p = max((abs(x[i] - x[j]) - 1) >> 1, (abs(y[i] - y[j]) - 1) >> 1);
			if( p <= t ) a[++cnt] = p;
		}
	a[++cnt] = t;
	sort(a + 1, a + cnt + 1), cnt = unique(a + 1, a + cnt + 1) - a - 1;
	int ans = mul(t + 1, func(t)), lst = 0;
	for(int i=1;i<=cnt;i++)
		ans = sub(ans, func2(lst, a[i])), lst = a[i] + 1;
	printf("%d\n", ans);
}