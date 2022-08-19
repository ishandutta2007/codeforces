#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;
ll gcd(ll x, ll y)
{
	return (y == 0 ? x : gcd(y, x % y));
}
ll lcm(ll x, ll y)
{
	return (x / gcd(x, y)) * y;
}

const int N = 111;
int g[N];
bool used[N];
int n;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &g[i]);
		g[i]--;
		if (used[g[i]])
		{
			printf("-1\n");
			return 0;
		}
		used[g[i]] = 1;
	}
	for (int i = 0; i < n; i++)
		used[i] = 0;
	ll ans = 1;
	for (int i = 0; i < n; i++)
	{
		if (used[i]) continue;
		int len = 0;
		int v = i;
		while(!used[v])
		{
			used[v] = 1;
			v = g[v];
			len++;
		}
		if (len & 1)
			ans = lcm(ans, len);
		else
			ans = lcm(ans, len / 2);
	}
	printf("%lld\n", ans);

	return 0;
}