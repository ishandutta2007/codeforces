#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005, seed1 = 500009, seed2 = 500029, p1 = 1e9 + 7, p2 = 1e9 + 9;
int T, n, m;
long long ans, c[Maxn], Hash1[Maxn], Hash2[Maxn];
map <pair <long long, long long> , long long> Ma;
long long gcd(long long x, long long y)
{
	return x == 0 ? y : gcd(y % x, x);
}
vector <int> Ve[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &c[i]), Hash1[i] = Hash2[i] = 0, Ve[i].clear();
		for (int i = 1; i <= m; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			Ve[y].push_back(x);
		}
		for (int u = 1; u <= n; u++)
		{
			sort(Ve[u].begin(), Ve[u].end());
			for (vector <int> :: iterator it = Ve[u].begin(); it != Ve[u].end(); it++)
			{
				Hash1[u] = (Hash1[u] * seed1 + *it) % p1;
				Hash2[u] = (Hash2[u] * seed2 + *it) % p2;
			}
		}
		Ma.clear();
		for (int i = 1; i <= n; i++)
			if (Ve[i].size())
				Ma[make_pair(Hash1[i], Hash2[i])] += c[i];
		for (map <pair <long long, long long> , long long> :: iterator it = Ma.begin(); it != Ma.end(); it++)
			ans = gcd(ans, it -> second);
		printf("%lld\n", ans);
	}
	return 0;
}