#include<bits/stdc++.h>
int main()
{
	int n, m, a[2010], count[2010], time = 0, ans, ans2;
	memset(count, 0, sizeof(count));
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	ans = n / m;
	printf("%d", ans);
	for (int i = 0; i < n; i++)
		if (a[i] <= m)
			count[a[i]]++;
	int i = 0,j = 1;
	while (j <= m)
	{
		if (count[j] >= ans)
		{
			j++;
			continue;
		}
		while (count[j] < ans)
		{
			if (a[i] > m)
			{
				a[i++] = j;
				count[j]++;
				time++;
			}
			else if (count[a[i]] > ans)
			{
				count[a[i]]--;
				a[i++] = j;
				count[j]++;
				time++;
			}
			else
				i++;
		}
		j++;
	}
	printf(" %d\n", time);
	for (int i = 0; i < n; i++)
		printf("%d ",a[i]);
	return 0;
}