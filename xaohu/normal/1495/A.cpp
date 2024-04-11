#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = b; i >= a; --i)

using ll = long long;
using namespace std;

const int N = 2e5;

int n;

void solve() {
	scanf("%d", &n);
	vector<int> x, y;
	rep(i, 1, 2 * n) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a < 0) a = -a;
		if (b < 0) b = -b;
		if (!a) x.pb(b);
		if (!b) y.pb(a);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	long double ans = 0;
	rep(i, 0, n - 1)
		ans += sqrt(ll(x[i]) * x[i] + ll(y[i]) * y[i]);
	printf("%.10Lf\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
	return 0;
}