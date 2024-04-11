#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int n, k, a[500005];
ll b[500005], sum, res = -(1LL << 60), curr;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) {
		b[i] = b[i - 1] + a[i];
		sum += 1LL * (i - 1) * a[i];
	}
	for (int i = 1; i <= n; ++i) {
		int mx = (i - 1 + k) / (k + 1), mn = (i - 1) / (k + 1);
		res = max(res, (b[n] - b[i - 1]) * mx + curr + sum);
		sum -= (b[n] - b[i]);
		curr += 1LL * mn * a[i];
	}
	res = max(res, curr);
	printf("%lld\n", res);
	return 0;
}