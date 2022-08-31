#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pil;
#define mp make_pair

const int N = 100100;
int n;
ll a[N];
ll d[N];
bool bad[N];
int ans = 0;
vector<pil> g[N];

void dfs(int v, int par)
{
	d[v] = max(d[v], 0LL);
	if (d[v] > a[v] || (par != -1 && bad[par]))
	{
		bad[v] = 1;
		ans++;
	}
	for (pil e : g[v])
	{
		int u = e.first;
		if (u == par) continue;
		d[u] = d[v] + e.second;
		dfs(u, v);
	}
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
		int v;
		ll w;
		scanf("%d%lld", &v, &w);
		v--;
		g[i].push_back(mp(v, w));
		g[v].push_back(mp(i, w));
	}
	dfs(0, -1);
	printf("%d\n", ans);

	return 0;
}