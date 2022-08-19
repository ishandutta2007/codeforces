#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
#define mp make_pair
#define X first
#define Y second

const int N = 200200;
int n;
int a[N];
pii b[N];
int par[N];
int sz[N];
int ans[N];

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
	par[u] = v;
	sz[v] += sz[u];
	return;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = mp(a[i], i);
	}
	sort(b, b + n);
	reverse(b, b + n);
	for (int i = 0; i < n; i++)
	{
		int p = b[i].Y;
		par[p] = -1;
		sz[p] = 1;
		if (p > 0 && sz[p - 1] > 0)
			unite(p, p - 1);
		if (p < n - 1 && sz[p + 1] > 0)
			unite(p, p + 1);
		int x = getPar(p);
		int s = sz[x];
		ans[s] = max(ans[s], a[p]);
	}
	int mm = 0;
	for (int i = n; i > 0; i--)
	{
		mm = max(mm, ans[i]);
		ans[i] = mm;
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}