#include<bits/stdc++.h>
const int N = 200010;
int n, a[N], cnt[N], sum[N];

void solve(int x)
{
	if (a[0] > a[x + 1])
	{
		cnt[x + 1]++;
		cnt[n + 1]--;
	}
	for (int i = 1, j = 0; j < x; i = j + 1)
	{
		j = x / (x / i);
		if (a[x / i] > a[x + 1])
		{
			cnt[i]++;
			cnt[j + 1]--;
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++)
		solve(i - 1);
	sum[1] = cnt[1];
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + cnt[i];
	for (int i = 1; i <= n - 1; i++)
		printf("%d ", sum[i]);
	return 0;
}