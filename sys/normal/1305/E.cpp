#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005;
int n, m, pos, a[Maxn], ans[Maxn], tmp[Maxn];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		a[i] = i;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (i + j <= n) ans[i + j]++;
	for (int i = 3; i <= n; i++)
		ans[i] += ans[i - 1];
	if (m > ans[n])
	{
		puts("-1");
		return 0;
	}
	for (int i = n; i >= 1; i--)
	{
		if (ans[i - 1] >= m) continue;
		for (int j = 1; j < i; j++)
			for (int k = j + 1; k < i; k++)
				tmp[j + k]++;
		while (tmp[a[i]] != m - ans[i - 1]) a[i]++;
		pos = i;
		break;
	}
	for (int i = n; i > pos; i--)
		a[i] = 1e9 - (a[pos] + 1) * (n - i);
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	return 0;
}