#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll INF = (ll)1e18 + 1;
const int N = 300300;
int n;
ll ans = -INF;
ll a[N];
ll sum[N];
vector<int> g[N];
bool used[N];

void dfs(int v)
{
	used[v] = 1;
	sum[v] = a[v];
	a[v] = -INF;
	ll m1 = -INF, m2 = -INF;
	for (int u : g[v])
	{
		if (used[u]) continue;
		dfs(u);
		sum[v] += sum[u];
		ll val = a[u];
		a[v] = max(a[v], val);
		if (m1 < val) swap(m1, val);
		if (m2 < val) swap(m2, val);
	}
	if (m2 > -INF) ans = max(ans, m1 + m2);
	a[v] = max(a[v], sum[v]);
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i < n; i++)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0);
	if (ans == -INF)
		printf("Impossible\n");
	else
		printf("%lld\n", ans);

	return 0;
}