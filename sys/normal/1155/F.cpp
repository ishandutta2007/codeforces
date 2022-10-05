#include <bits/stdc++.h>
using namespace std;

const int Maxn = 15;
int n, m, f[1 << Maxn | 5], Chain[Maxn][Maxn][1 << Maxn | 5];
bool G[Maxn][Maxn];
pair <pair <int, int>, int> from[1 << Maxn | 5];
void get_chain(pair <pair <int, int>, int> s)
{
	if (s.second == (s.second & -s.second)) return ;
	printf("%d %d\n", s.first.second, Chain[s.first.first][s.first.second][s.second]);
	get_chain(make_pair(make_pair(s.first.first, Chain[s.first.first][s.first.second][s.second]), (s.second ^ (1 << (s.first.second - 1))) | (1 << (s.first.first - 1))));
}
void print(int sta)
{
	if (!sta || sta == (sta & -sta)) return ;
	get_chain(from[sta]);
	if (from[sta].first.first != from[sta].first.second)
		print(sta ^ from[sta].second ^ (1 << (from[sta].first.first - 1)) ^ (1 << (from[sta].first.second - 1)));
	else print(sta ^ from[sta].second ^ (1 << (from[sta].first.first - 1)));
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x][y] = G[y][x] = true;
	}
	int maxi = (1 << n) - 1;
	for (int i = 1; i <= n; i++)
		Chain[i][i][1 << (i - 1)] = -1;
	for (int i = 0; i <= maxi; i++)
		for (int x = 1; x <= n; x++)
			if (i & (1 << (x - 1)))
				for (int y = 1; y <= n; y++)
					if (Chain[x][y][i] && (!(x == y) || (i == (1 << (x - 1)))))
						for (int j = 1; j <= n; j++)
							if ((!(i & (1 << (j - 1))) || (i != ((1 << (x - 1)) | (1 << (y - 1))) && x == j)) && G[y][j])
								Chain[x][j][i | (1 << (j - 1))] = y;
	memset(f, 0x3f, sizeof(f));
	f[1] = 0;
	for (int i = 1; i <= maxi; i++)
		if (f[i] != 0x3f3f3f3f)
			for (int x = 1; x <= n; x++)
				if (i & (1 << (x - 1)))
					for (int y = 1; y <= n; y++)
						if (i & (1 << (y - 1)))
							for (int j = maxi ^ i; j; j = (j - 1) & (maxi ^ i))
								if (Chain[x][y][j | (1 << (x - 1)) | (1 << (y - 1))] && f[i | j] > f[i] + 1)
									f[i | j] = f[i] + 1, from[i | j] = make_pair(make_pair(x, y), j | (1 << (x - 1)) | (1 << (y - 1)));
	printf("%d\n", n - 1 + f[maxi]);
	print(maxi);
	return 0;
}