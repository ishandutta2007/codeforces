#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
int n, m, W, ans, w[Maxn], b[Maxn], fa[Maxn], f[Maxn], g[Maxn];
vector <int> Ve[Maxn];
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
void merge(int x, int y)
{
	int a = get_fa(x), b = get_fa(y);
	fa[a] = b;
}
int main()
{
	scanf("%d%d%d", &n, &m, &W);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]), fa[i] = i;
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		merge(x, y);
	}
	for (int i = 1; i <= n; i++)
		Ve[get_fa(i)].push_back(i);
	for (int i = 1; i <= n; i++)
	{
		int sum_w = 0, sum_b = 0;
		memcpy(g, f, sizeof(int[W + 1]));
		for (auto now : Ve[i])
		{
			for (int j = w[now]; j <= W; j++)
				f[j] = max(f[j], g[j - w[now]] + b[now]);
			sum_w += w[now];
			sum_b += b[now];
		}
		for (int j = sum_w; j <= W; j++)
			f[j] = max(f[j], g[j - sum_w] + sum_b);
	}
	for (int i = 0; i <= W; i++)
		ans = max(ans, f[i]);
	printf("%d", ans);
	return 0;
}