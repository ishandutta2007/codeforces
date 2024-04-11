#include <bits/stdc++.h>

typedef long long ll;

const int N = 100000;
const ll INF = (1ll << 62);

struct point{ll x, y;}pnt[N + 5], tmp[N + 5];
bool cmpx(const point &a, const point &b) {
	return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
}
bool cmpy(const point &a, const point &b) {
	return (a.y == b.y) ? (a.x < b.x) : (a.y < b.y);
}

ll pw2(ll x) {return x * x;}
ll dist(const point &a, const point &b) {return pw2(a.x - b.x) + pw2(a.y - b.y);}
ll solve(int l, int r) {
	if( l == r ) return INF;
	
	int m = (l + r) >> 1; ll xm = pnt[m].x;
	ll ret = std::min(solve(l, m), solve(m + 1, r));
	
	int pl = l, pr = m + 1, p = l;
	while( pl <= m && pr <= r ) {
		if( cmpy(pnt[pl], pnt[pr]) ) tmp[p++] = pnt[pl++];
		else tmp[p++] = pnt[pr++];
	}
	while( pl <= m ) tmp[p++] = pnt[pl++];
	while( pr <= r ) tmp[p++] = pnt[pr++];
	for(int i=l;i<=r;i++) pnt[i] = tmp[i];
	
	std::vector<point>v;
	for(int i=l;i<=r;i++) if( pw2(pnt[i].x - xm) <= ret )
		v.push_back(pnt[i]);
	for(int i=0;i<(int)v.size();i++) {
		for(int j=i-1;j>=0;j--) {
			if( pw2(v[i].y - v[j].y) > ret ) break;
			ret = std::min(ret, dist(v[i], v[j]));
		}
	}
	return ret;
}

int main() {
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%lld", &pnt[i].y), pnt[i].x = i, pnt[i].y += pnt[i - 1].y;
	std::sort(pnt + 1, pnt + n + 1, cmpx), printf("%lld\n", solve(1, n));
}