#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n;
long long s, ans, a[Maxn];
map <long long, long long> f, g;
int main()
{
	scanf("%d%lld", &n, &s);
	f[s - 1] = 0;
	for (int i = 1; i < n; i++)
	{
		long long x;
		scanf("%lld", &x);
		for (map <long long, long long> :: iterator it = f.lower_bound(x); it != f.end(); it++)
		{
			pair <long long, long long> now = *it;
			if (g.find(now.first % x) == g.end()) g[now.first % x] = -0x3f3f3f3f3f3f3f3fLL;
			if (g.find(x - 1) == g.end()) g[x - 1] = -0x3f3f3f3f3f3f3f3fLL;
			g[now.first % x] = max(g[now.first % x], now.second + i * (now.first - now.first % x));
			if (now.first >= x - 1) g[x - 1] = max(g[x - 1], now.second + i * ((now.first - x + 1) / x * x));
		}
		while (f.size() && f.rbegin() -> first >= x) f.erase(f.rbegin() -> first);
		for (auto now : g) f[now.first] = max(f[now.first], now.second);
		g.clear();
	}
	for (auto now : f)
		ans = max(ans, now.first * n + now.second);
	printf("%lld", ans);
	return 0;
}