#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 200100;
ll a[N];
int p[N];
ll ans[N];
int sz[N], par[N];
ll sum[N];
ll cur;
int n;

int getPar(int v)
{
	return (par[v] == -1 ? v : par[v] = getPar(par[v]));
}
void unite(int v, int u)
{
	v = getPar(v);
	u = getPar(u);
	if (v == u) return;
	if (sz[v] < sz[u]) swap(v, u);
	sz[v] += sz[u];
	sum[v] += sum[u];
	par[u] = v;
	return;
}

void on(int v)
{
	sz[v] = 1;
	sum[v] = a[v];
	if (v > 0 && sz[v - 1] > 0) unite(v - 1, v);
	if (v < n - 1 && sz[v + 1] > 0) unite(v, v + 1);
	cur = max(cur, sum[getPar(v)]);
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
		p[i]--;
	}
	for (int i = 0; i < n; i++)
	{
		sz[i] = 0;
		par[i] = -1;
		sum[i] = 0;
	}
	cur = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		ans[i] = cur;
		on(p[i]);
	}
	for (int i = 0; i < n; i++)
		printf("%lld\n", ans[i]);

	return 0;
}