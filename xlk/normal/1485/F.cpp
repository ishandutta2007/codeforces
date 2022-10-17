#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int t, n, x;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		map<long long, int> g;
		scanf("%d", &n);
		int z = 1;
		long long s = 0;
		g[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			int f = (z + p - g[s]) % p;
			g[s] = (g[s] + f) % p;
			s += x;
			z = (z + f) % p;
		}
		printf("%d\n", z);
	}
	return 0;
}