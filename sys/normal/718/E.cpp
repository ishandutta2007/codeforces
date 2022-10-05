#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005, Maxc = 29;
int n, dis[Maxn][Maxc], disc[Maxc][Maxc], cnt[Maxc][261], sta[Maxn];
queue <int> Qu;
char c[Maxn];
pair <int, long long> ans;
void bfs(int x)
{
	for (int i = 1; i <= n; i++)
		if (c[i] == x - 1 + 'a') Qu.push(i), dis[i][x] = 0;
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		if (u - 1 >= 1 && dis[u - 1][x] == 0x3f3f3f3f)
		{
			dis[u - 1][x] = dis[u][x] + 1;
			Qu.push(u - 1);
		}
		if (u + 1 <= n && dis[u + 1][x] == 0x3f3f3f3f)
		{
			dis[u + 1][x] = dis[u][x] + 1;
			Qu.push(u + 1);
		}
	}
}
void update(int x, int y)
{
	if (x == ans.first) ans.second += y;
	if (x > ans.first) ans = make_pair(x, y);
}
int main()
{
	scanf("%d", &n);
	memset(dis, 0x3f, sizeof(dis));
	memset(disc, 0x3f, sizeof(disc));
	for (int i = 1; i <= n; i++)
	{
		c[i] = getchar();
		while (!isalpha(c[i])) c[i] = getchar();
	}
	for (int i = 1; i <= 8; i++)
		bfs(i);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 8; j++)
			for (int k = 1; k <= 8; k++)
				disc[j][k] = min(disc[j][k], dis[i][j] + dis[i][k]);
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			for (int k = 1; k <= 8; k++)
				disc[j][k] = min(disc[j][k], disc[j][i] + disc[i][k] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 8; j++)
			for (int k = 1; k <= 8; k++)
				dis[i][k] = min(dis[i][k], dis[i][j] + disc[j][k] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 8; j++)
			if (disc[c[i] - 'a' + 1][j] != dis[i][j]) sta[i] |= 1 << (j - 1);
	for (int i = 1; i <= n; i++)
		for (int j = max(1, i - 15); j < i; j++)
		{
			int d = i - j;
			for (int k = 1; k <= 8; k++)
				d = min(d, dis[j][k] + dis[i][k] + 1);
			update(d, 1);
		}
	for (int i = 1; i <= n; i++)
	{
		if (i - 16 >= 1) cnt[c[i - 16] - 'a' + 1][sta[i - 16]]++;
		for (int j = 1; j <= 8; j++)
			for (int k = 0; k <= 255; k++)
				if (cnt[j][k])
				{
					int d = 0x3f3f3f3f;
					for (int q = 1; q <= 8; q++)
						d = min(d, dis[i][q] + disc[j][q] + ((k >> (q - 1)) & 1) + 1);
					update(d, cnt[j][k]);
				}
	}
	printf("%d %lld", ans.first, ans.second);
	return 0;
}