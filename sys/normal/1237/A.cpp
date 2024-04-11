#include <bits/stdc++.h>
using namespace std;
const int Maxn = 20005;
int n, a[Maxn], b[Maxn];
long long sum;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), b[i] = floor(a[i] / 2.0), sum += b[i];
	if (!sum)
	{
		for (int i = 1; i <= n; i++)
			printf("%d\n", b[i]);
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] % 2) b[i]++, sum++;
		if (!sum)
		{
			for (int i = 1; i <= n; i++)
				printf("%d\n", b[i]);
			return 0;
		}
	}
}