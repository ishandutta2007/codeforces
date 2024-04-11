#include "bits/stdc++.h"
using namespace std;

int a[200005], b[200005];
int c[200005], d[200005];

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int x, s;
	scanf("%d%d", &x, &s);
	for (int i = 0; i < m; i++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]);
	a[m] = x; b[m] = 0;
	for (int i = 0; i < k; i++) scanf("%d", &c[i]);
	for (int i = 0; i < k; i++) scanf("%d", &d[i]);

	unsigned long long ans = 8e18;

	for (int i = 0; i <= m; i++)
	{
		if (s < b[i]) continue;
		int idx = upper_bound(d, d + k, s - b[i]) - d - 1;
		if (idx < 0) ans = min(ans, (unsigned long long)n * a[i]);
		else ans = min(ans, (unsigned long long)(n - c[idx]) * a[i]);
	}

	printf("%llu", ans);
}