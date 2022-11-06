#include<stdio.h>
#include<map>
int d(long long x)
{
	int r = 0;
	for (; x >> r; r++);
	return r;
}
long long lca(long long a, long long b)
{
	if (a > b) a ^= b ^= a ^= b;
	int da = d(a), db = d(b);
	b >>= db - da;
	while (a != b) { a /= 2; b /= 2; }
	return a;
}
int main()
{
	int q, n, i, j;
	scanf("%d", &q);
	std::map<long long, long long> M;
	for (i = 1; i <= q; i++)
	{
		int t;
		long long v, u, w;
		scanf("%d", &t);
		if (t == 1)
		{
			scanf("%lld%lld%lld", &v, &u, &w);
			long long l = lca(v, u);
			while (v != l)
			{
				if (M.count(v) == 0) M[v] = w;
				else M[v] += w;
				v /= 2;
			}
			while (u != l)
			{
				if (M.count(u) == 0) M[u] = w;
				else M[u] += w;
				u /= 2;
			}
		}
		else
		{
			scanf("%lld%lld", &v, &u);
			long long l = lca(v, u), ans = 0;
			while (v != l)
			{
				if (M.count(v) != 0) ans += M[v];
				v /= 2;
			}
			while (u != l)
			{
				if (M.count(u) != 0) ans += M[u];
				u /= 2;
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}