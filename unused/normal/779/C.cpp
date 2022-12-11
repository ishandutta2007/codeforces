#include <bits/stdc++.h>
using namespace std;

int d1[200005], d2[200005];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	long long ans = 0;
	for (int i = 0; i < n; i++) scanf("%d", &d1[i]);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &d2[i]);
		ans += d2[i];
		d1[i] -= d2[i];
	}
	sort(d1, d1 + n);
	for (int i = 0; i < n && (i < k || d1[i] < 0); i++) ans += d1[i];
	printf("%lld\n", ans);
}