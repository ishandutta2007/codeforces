#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;
int n;
long long ans = 0x3f3f3f3f3f3f3f3fLL, tmp, a[Maxn], b[Maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		tmp = 0;
		b[i] = 0;
		for (int j = i - 1; j >= 1; j--)
		{
			long long c = b[j + 1] / a[j] + 1;
			tmp += c;
			b[j] = c * a[j];
		}
		for (int j = i + 1; j <= n; j++)
		{
			long long c = b[j - 1] / a[j] + 1;
			tmp += c;
			b[j] = c * a[j];
		}
		ans = min(ans, tmp);
	}
	printf("%lld", ans);
	return 0;
}