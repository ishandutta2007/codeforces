#include <bits/stdc++.h>

typedef long long ll;

const int N = 400000;
const double PI = acos(-1);
const double EPS = 1E-12;

struct point{
	double x, y;
}p[N + 5]; int n;

int dcmp(double x) {return fabs(x) < EPS ? 0 : (x > 0 ? 1 : -1);}
bool cmp(double x, double y) {return dcmp(x - y) < 0;}
bool equ(double x, double y) {return dcmp(x - y) == 0;}
double pw2(double x) {return x * x;}
double geta(double a) {
	while( a > 2*PI ) a -= 2*PI;
	while( a < 0 ) a += 2*PI;
	return a;
}

std::vector<double>v; int tree[N + 5], s;
int sum(int x) {
	int ret = 0;
	for(int i=x;i;i-=(i&(-i))) ret += tree[i];
	return ret;
}
void update(int x, int k) {
	for(int i=x;i<=s;i+=(i&(-i))) tree[i] += k;
}

int le[N + 5], ri[N + 5];
std::vector<int>q1[N + 5], q2[N + 5];
ll check(double k) {
	v.clear(); int cnt = 0;
	for(int i=1;i<=n;i++) {
		if( pw2(p[i].x) + pw2(p[i].y) <= k * k )
			cnt++;
		else {
			double a = atan2(p[i].y, p[i].x);
			double t = acos(k / sqrt(pw2(p[i].x) + pw2(p[i].y)));
			double l = geta(a - t), r = geta(a + t);
			v.push_back(l), v.push_back(r);
		}
	}
	ll ret = 1ll * cnt * n - 1ll * cnt * (cnt - 1) / 2;
	
	std::sort(v.begin(), v.end(), cmp);
	v.erase(std::unique(v.begin(), v.end(), equ), v.end());
	s = (int)v.size();
	
	for(int i=1;i<=s;i++) tree[i] = 0, q1[i].clear(), q2[i].clear();
	for(int i=1;i<=n;i++) if( pw2(p[i].x) + pw2(p[i].y) > k * k ) {
		double a = atan2(p[i].y, p[i].x);
		double t = acos(k / sqrt(pw2(p[i].x) + pw2(p[i].y)));
		double l = geta(a - t), r = geta(a + t);
		le[i] = std::lower_bound(v.begin(), v.end(), l, cmp) - v.begin() + 1;
		ri[i] = std::lower_bound(v.begin(), v.end(), r, cmp) - v.begin() + 1;
		if( le[i] > ri[i] ) std::swap(le[i], ri[i]);
		q1[le[i]].push_back(i), q2[ri[i]].push_back(i);
	}
	
	for(int i=1;i<=s;i++) {
		for(auto x : q1[i]) ret -= (sum(ri[x] - 1) - sum(le[x] - 1));
		for(auto x : q1[i]) update(ri[x], 1);
		for(auto x : q2[i]) ret += sum(ri[x]);
	}
	
	return ret - n;
}

int main() {
	ll k; scanf("%d%lld", &n, &k);
	for(int i=1;i<=n;i++) {
		int x, y; scanf("%d%d", &x, &y);
		p[i].x = x, p[i].y = y;
	}
	
	double l = 0, r = 1E9;
	for(int i=1;i<=60;i++) {
		double mid = (l + r) / 2;
		if( check(mid) >= k ) r = mid;
		else l = mid;
	}
	printf("%.9f\n", l);
}