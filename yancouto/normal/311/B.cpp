// WA
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 100009;

struct li {
	ll a, b; // y = ax + b
	double end;
};

double x_inter(li l1, li l2) {
	return double(l2.b - l1.b) / (l1.a - l2.a);
}

li st[N]; int sn;

ll min_val(ll x) {
	int l = 0, r = sn - 1;
	while(l < r) {
		int m = (l + r) / 2;
		if(st[sn - 1 - m].end >= x) r = m;
		else l = m + 1;
	}
	l = sn - 1 - l;
	return st[l].a * x + st[l].b;
}

ll c[N], dp[N][102], acc[N], d[N];
int m;

void calc(int p) {
	int i;
	sn = 0;
	for(i = m - 1; i >= 0; i--) {
		li l = {-c[i], dp[i + 1][p - 1] + c[i] * ll(i + 1) - acc[i]};
		while(sn)
			if(st[sn-1].a == l.a && l.b < st[sn - 1].b) sn--;
			else if(st[sn-1].a != l.a && x_inter(l, st[sn - 1]) >= st[sn - 1].end) sn--;
			else break;
		if(!sn || st[sn - 1].a != l.a) {
			l.end = sn? x_inter(l, st[sn - 1]) : 1/0.;
			st[sn++] = l;
		}
		dp[i][p] = min_val(i) + (i? acc[i - 1] : 0ll);
	}
}

int main() {
	int n, p, i, h, t, x;
	scanf("%d %d %d", &n, &m, &p);
	for(i = 1; i < n; i++) {
		scanf("%d", &x);
		d[i] = d[i - 1] + x;
	}
	for(i = 0; i < m; i++) {
		scanf("%d %d", &h, &t);
		c[i] = t - d[h - 1];
	}
	sort(c, c + m);
	for(i = m - 1; i >= 0; i--)
		c[i] -= c[0] - 1;
	for(i = 0; i < m; i++)
		acc[i] = c[i] + (i? acc[i - 1] : 0);
	dp[m][0] = 0;
	for(i = 0; i < m; i++)
		dp[i][0] = 100000000000000000ll;
	for(i = 1; i <= p; i++)
		calc(i);
	printf("%I64d\n", dp[0][p]);
}