#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y)
{
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y)
{
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y)
{
	return (x * y) % MOD;
}

const int N = 200200;
vector<int> g[N];
int deg[N];
bool used[N];
int q[N];
int topQ;
int n;
int sz;

void dfs(int v)
{
	used[v] = 1;
	sz++;
	for (int u : g[v])
		if (!used[u])
			dfs(u);
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll ans = 1;
	scanf("%d", &n);
	for (int v = 0; v < n; v++)
	{
		int u;
		scanf("%d", &u);
		u--;
		g[v].push_back(u);
		g[u].push_back(v);
		deg[v]++;
		deg[u]++;
	}
	for (int v = 0; v < n; v++)
	{
		if (deg[v] == 1)
		{
			used[v] = 1;
			q[topQ++] = v;
		}
	}
	for (int k = 0; k < topQ; k++)
	{
		ans = add(ans, ans);
		int v = q[k];
		for (int u : g[v])
		{
			deg[u]--;
			if (deg[u] == 1)
			{
				used[u] = 1;
				q[topQ++] = u;
			}
		}
	}
	for (int v = 0; v < n; v++)
	{
		if (used[v]) continue;
		sz = 0;
		dfs(v);
		ll x = 1;
		while (sz--)
			x = add(x, x);
		x = sub(x, 2);
		ans = mult(ans, x);
	}
	printf("%lld\n", ans);

	return 0;
}