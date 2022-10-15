#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m, a[400001], b[400001], k, sum[400001];
void checkmin(int &x, int y)
{
	if (x > y)
	{
		x = y;
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	m = m * 8 / n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == a[i - 1])
		{
			b[k]++;
		}
		else
		{
			b[++k]++;
		}
	}
	int tmp = 1, ans = n;
	for (int i = 1; i <= m; i++)
	{
		tmp <<= 1;
		if (tmp > k)
		{
			printf("0");
			return 0;
		}
	}
	for (int i = 1; i <= k; i++)
	{
		sum[i] = sum[i - 1] + b[i];
	}
	for (int i = 1; i <= k - tmp + 1; i++)
	{
		int l = i, r = i + tmp - 1;
		checkmin(ans, sum[k] - (sum[r] - sum[l - 1]));
	}
	printf("%d", ans);
	return 0;
}