#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
int n, a[Maxn], sum[Maxn];
long long tot, ans, sum2[Maxn];
int lowbit(int x)
{
	return x & -x;
}
void add(int x)
{
	for (int i = x; i <= 300000; i += lowbit(i))
		sum[i]++;
}
int ask(int x)
{
	x = min(x, 300000);
	x = max(x, 0);
	int result = 0;
	for (int i = x; i; i -= lowbit(i))
		result += sum[i];
	return result;
}
void add2(int x, long long y)
{
	if (!y) return ;
	for (int i = x; i <= 300000; i += lowbit(i))
		sum2[i] += y;
}
long long ask2(int x)
{
	x = min(x, 300000);
	x = max(x, 0);
	long long result = 0;
	for (int i = x; i; i -= lowbit(i))
		result += sum2[i];
	return result;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		ans += tot + a[i] * (i - 1LL);
		tot += a[i];
		ans -= ask2(a[i]); 
		for (int j = 0; j <= 300000; j += a[i])
		{
			int v = ask(j + a[i] - 1) - ask(j - 1);
			ans -= 1LL * v * (j / a[i]) * a[i];
			add2(j, j / a[i] * 1LL * a[i]), add2(j + a[i], -j / a[i] * 1LL * a[i]);
		}
		add(a[i]);
		printf("%lld ", ans);
	}
	return 0;
}