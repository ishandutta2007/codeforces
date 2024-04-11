#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int maxn = 200010;
int m, n, a[maxn];
ll s[maxn], p[maxn];
pll Q[maxn];
double K[maxn];
double getk(pll A) {
	return 1.0 * A.second / A.first;
}
double getk(pll A, pll B) {
	return getk(make_pair(B.first - A.first, B.second - A.second));
}
void add(pll x) {
	while (m > 1 && getk(Q[m], x) > getk(Q[m - 1], Q[m])) --m;
	Q[++m] = x;
	if (m > 1) K[m - 1] = -getk(Q[m - 1], Q[m]);
}
inline ll getv(pll l, ll x) {
	return -l.first * x + l.second;
}
ll query(ll x) {
	if (m == 1) return getv(Q[m], x);
	int r = lower_bound(K + 1, K + m, -x) - K;
	return getv(Q[r], x);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		s[i] = s[i - 1] + a[i];
		p[i] = p[i - 1] + 1LL * a[i] * i;
	}
	
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		add(make_pair(i, (i - 1) * s[i - 1] - p[i - 1]));
		ans = max(ans, s[i] + p[i] + query(s[i]));
	}
	printf("%I64d\n", ans);
}