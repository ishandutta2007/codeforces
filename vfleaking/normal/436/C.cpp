#include <iostream>
#include <cstdio>
#include <climits>
#include <numeric>
using namespace std;

const int MaxNK = 1000;
const int MaxN = 10;
const int MaxM = 10;

// adjust
template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tension(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

int n, m, nK, w;
char a[MaxNK + 1][MaxN][MaxM + 1];

int getD(int i, int j)
{
	int d = 0;
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
			d += a[i][x][y] != a[j][x][y];
	return d;
}

int main()
{
	cin >> n >> m >> nK >> w;
	for (int i = 1; i <= nK; i++)
		for (int x = 0; x < n; x++)
			scanf("%s", a[i][x]);

	static int dist[MaxNK + 1], distP[MaxNK + 1];
	fill(dist + 1, dist + nK + 1, n * m);

	static int q[MaxNK];
	static bool orz[MaxNK + 1];
	static bool book[MaxNK + 1];
	int top, bot;
	top = bot = 0;

	for (int sv = 1; sv <= nK; sv++)
		if (dist[sv] == n * m)
		{
			q[bot++] = sv, book[sv] = true;
			while (top != bot)
			{
				for (int i = top + 1; i < bot; i++)
					if (dist[q[i]] < dist[q[top]])
						swap(q[i], q[top]);
				int v = q[top++];
				orz[v] = true;
				for (int u = 1; u <= nK; u++)
					if (!orz[u])
					{
						int d = getD(v, u);
						if (d * w <= n * m && tension(dist[u], d * w))
						{
							distP[u] = v;
							if (!book[u])
								q[bot++] = u, book[u] = true;
						}
					}
			}
		}

	cout << accumulate(dist + 1, dist + nK + 1, 0) << endl;
	for (int i = 0; i < nK; i++)
		printf("%d %d\n", q[i], distP[q[i]]);

	return 0;
}