#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, x[Maxn], y[Maxn];
int main()
{
	scanf("%d", &n);
	if (n & 1)
	{
		puts("No");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &x[i], &y[i]), x[i + n] = x[i], y[i + n] = y[i];
	for (int i = 1; i <= n; i++)
	{
		int tmp = i + n / 2;
		if (x[i + 1] - x[i] != x[tmp] - x[tmp + 1] || y[i + 1] - y[i] != y[tmp] - y[tmp + 1])
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}