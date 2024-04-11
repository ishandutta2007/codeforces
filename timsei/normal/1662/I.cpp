#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const double eps = 0.1;
int n, m, p[maxn], x[maxn], met[maxn];
long long sum[maxn];
inline long long Check(int l, int r, int pl, int pr, double now) {
	int l1 = upper_bound(met + l, met + r + 1, (pl + now) / 2) - met;
	int r1 = lower_bound(met + l, met + r + 1, (now + pr) / 2) - met - 1;
// cerr << l << " " << r << " " << pl << " " << pr << " " << now << " " << l1 << " " << r1 << " " << sum[r1] << " " << sum[l1 - 1] << endl;
// cerr << (pl + now) / 2 << " " << (now + pr) / 2 << endl;
	return r1 < l1 ? 0 : sum[r1] - sum[l1 - 1];
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++ i)
		scanf("%d", &p[i]), met[i] = (i - 1) * 100, sum[i] = sum[i - 1] + p[i];
	for(int i = 1; i <= m; ++ i)
		scanf("%d", &x[i]);
	sort(x + 1, x + m + 1);
	long long ans = sum[lower_bound(met + 1, met + n + 1, x[1]) - met - 1];
	int p = upper_bound(met + 1, met + n + 1, x[m]) - met;
	ans = max(ans, sum[n] - sum[p - 1]);
	for(int i = 1; i < m; ++ i) {
		int l = upper_bound(met + 1, met + n + 1, x[i]) - met, r = lower_bound(met + 1, met + n + 1, x[i + 1]) - met - 1;
		if(l > r)
			continue;
		ans = max(ans, Check(l, r, x[i], x[i + 1], (met[l] + x[i]) / 2. + eps));
		for(int j = l; j <= r; ++ j) {
			ans = max(ans, Check(l, r, x[i], x[i + 1], met[j] + eps));
			ans = max(ans, Check(l, r, x[i], x[i + 1], met[j] - eps));
			if(2 * met[j] - x[i] >= x[i] && 2 * met[j] - x[i] <= x[i + 1]) {
				ans = max(ans, Check(l, r, x[i], x[i + 1], 2 * met[j] - x[i] + eps));
				ans = max(ans, Check(l, r, x[i], x[i + 1], 2 * met[j] - x[i] - eps));
			}
			if(2 * met[j] - x[i + 1] >= x[i] && 2 * met[j] - x[i + 1] <= x[i + 1]) {
				ans = max(ans, Check(l, r, x[i], x[i + 1], 2 * met[j] - x[i + 1] + eps));
				ans = max(ans, Check(l, r, x[i], x[i + 1], 2 * met[j] - x[i + 1] - eps));
			}
		}
		for(int j = l; j < r; ++ j) {
			ans = max(ans, Check(l, r, x[i], x[i + 1], (met[j] + met[j + 1]) / 2. + eps));
			ans = max(ans, Check(l, r, x[i], x[i + 1], (met[j] + met[j + 1]) / 2. - eps));
		}
		ans = max(ans, Check(l, r, x[i], x[i + 1], (met[r] + x[i]) / 2. - eps));
	}
	printf("%lld\n", ans);
}