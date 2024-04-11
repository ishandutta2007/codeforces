#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair

const int INF = (int)1e9 + 3;
const int N = 310;
int n, m, p;
vector<pii> a[N * N];
vector<pii> b[2][N];
int idx[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &p);
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
		{
			int z;
			scanf("%d", &z);
			z--;
			a[z].push_back(mp(x, y));
		}
	b[0][0].push_back(mp(0, 0));
	int t = 0, nt = 1;
	for (int val = 0; val < p; val++)
	{
		for (int y = 0; y < m; y++)
		{
			b[nt][y].clear();
			idx[y] = 0;
		}
		for (pii cl : a[val])
		{
			int X = cl.first, Y = cl.second;
			int w = INF;
			for (int y = 0; y < m; y++)
			{
				while(idx[y] + 1 < (int)b[t][y].size() && b[t][y][idx[y] + 1].first <= X) idx[y]++;
				if (idx[y] < (int)b[t][y].size())
					w = min(w, b[t][y][idx[y]].second + abs(b[t][y][idx[y]].first - X) + abs(y - Y));
				if (idx[y] + 1 < (int)b[t][y].size())
					w = min(w, b[t][y][idx[y] + 1].second + abs(b[t][y][idx[y] + 1].first - X) + abs(y - Y));
			}
			b[nt][Y].push_back(mp(X, w));
		}
		swap(t, nt);
	}
	printf("%d\n", b[t][a[p - 1][0].second][0].second);

	return 0;
}