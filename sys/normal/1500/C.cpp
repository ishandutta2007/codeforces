#include <bits/stdc++.h>
using namespace std;

const int Maxn = 3005;
const int p1 = 1e9 + 7, p2 = 1e9 + 9, seed1 = 1511, seed2 = 1523;
int n, m, ct, p[Maxn], ord[Maxn], bel[Maxn], Left[Maxn], a[Maxn][Maxn], b[Maxn][Maxn];
vector <int> tmp[Maxn];
bool work(void)
{
	int pos = 0;
	for (int i = 1; i <= m; i++)
		if (!Left[i])
		{
			pos = i;
			Left[i] = -1;
			break;
		}
	if (!pos) return false;
	p[++ct] = pos;
	for (int i = 2; i <= n; i++)
		if (bel[i] == bel[i - 1] && b[i - 1][pos] != b[i][pos])
			for (int j = 1; j <= m; j++)
				if (b[i - 1][j] > b[i][j]) Left[j]--;
	for (int i = 2; i <= n; i++)
	{
		bel[i] = max(bel[i], bel[i - 1]);
		if (bel[i] == bel[i - 1] && b[i - 1][pos] != b[i][pos])
			bel[i] = i;
	}
	return true;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) bel[i] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &b[i][j]);
	for (int j = 1; j <= m; j++)
		for (int i = 2; i <= n; i++)
			Left[j] += (b[i][j] < b[i - 1][j]);
	while (work());
	for (int i = 1; i <= n; i++) ord[i] = i;
	sort(ord + 1, ord + 1 + n, [](int x, int y)
	{
		for (int i = 1; i <= ct; i++)
			if (a[x][p[i]] != a[y][p[i]]) return a[x][p[i]] < a[y][p[i]];
		return x < y;
	});
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[ord[i]][j] != b[i][j])
			{
				puts("-1");
				return 0;
			}
	printf("%d\n", ct);
	for (int i = ct; i >= 1; i--)
		printf("%d ", p[i]);
	return 0;
}