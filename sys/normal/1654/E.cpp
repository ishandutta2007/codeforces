#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, ans, a[Maxn], ct[Maxn], ct2[805 * Maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= min(i + 400, n); j++)
			if ((a[j] - a[i]) % (j - i) == 0) ans = max(ans, 1 + (++ct[100000 + (a[j] - a[i]) / (j - i)]));
		for (int j = i + 1; j <= min(i + 400, n); j++) ct[100000 + (a[j] - a[i]) / (j - i)] = 0;
	}
	for (int j = -400; j <= 400; j++)
	{
		for (int i = 1; i <= n; i++)
			ans = max(ans, ++ct2[400 * n + a[i] - i * j]);
		for (int i = 1; i <= n; i++)
			ct2[400 * n + a[i] - i * j] = 0;
	}
	printf("%d", n - ans);
	return 0;
}