#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
int T, n, d[Maxn], dis_a1[Maxn], dis_a2[Maxn], dis_b1[Maxn], dis_b2[Maxn];
long long fib[Maxn];
void init(long long x, int c, int dis1[], int dis2[])
{
	if (!c) return ;
	if (c == 1)
	{
		dis1[1] = x != 1;
		dis2[1] = x != 2;
		return ;
	}
	if (x <= fib[c - 1])
	{
		init(x, c - 1, dis1, dis2);
		dis1[c] = min(dis1[c - 1], dis2[c - 1] + 2);
		dis2[c] = min(dis1[c - 1], dis2[c - 1]) + d[c - 2] + 1;
	}
	else
	{
		init(x - fib[c - 1], c - 2, dis1, dis2);
		dis1[c] = dis1[c - 2] + 1;
		dis2[c] = dis2[c - 2];
	}
}
int work(long long x, long long y, int c)
{
	if (c <= 1) return x != y;
	if (x > fib[c - 1] && y > fib[c - 1]) return work(x - fib[c - 1], y - fib[c - 1], c - 2);
	if (y > fib[c - 1]) return dis_b1[c - 2] + min(dis_a1[c - 1], dis_a2[c - 1]) + 1;
	if (x > fib[c - 1]) return dis_a1[c - 2] + min(dis_b1[c - 1], dis_b2[c - 1]) + 1;
	return min(min(dis_a1[c - 1] + dis_b2[c - 1], dis_a2[c - 1] + dis_b1[c - 1]) + 2, work(x, y, c - 1));
}
int main()
{
	scanf("%d%d", &T, &n);
	d[1] = 1;
	fib[0] = 1, fib[1] = 2;
	for (int i = 2; i <= n; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		if (fib[i] >= 3e16)
		{
			n = i;
			break;
		}
	}
	for (int i = 2; i <= n; i++) d[i] = d[i - 2] + 1;
	while (T--)
	{
		long long a, b;
		scanf("%lld%lld", &a, &b);
		init(a, n, dis_a1, dis_a2), init(b, n, dis_b1, dis_b2);
		printf("%d\n", work(a, b, n));
	}
	return 0;
}