#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
#include <cassert>
#include <complex>
#include <valarray>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)3e3 + 100;
const int INF = (int)1e9 + 10;
vector <int> g[N];
int n, m;

void read()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].push_back(b);
	}
}

int d[N][N];
int q[N];
int r = 0;

void bfs(int st, int *dist)
{
	r = 0;
	fill(dist, dist + n, INF);
	dist[st] = 0;
	q[r++] = st;
	for (int i = 0; i < r; i++)
	{
		int v = q[i];
		for (int to : g[v])
		{
			if (dist[to] > dist[v] + 1)
			{
				dist[to] = dist[v] + 1;
				q[r++] = to;
			}
		}
	}
}

vector<int> sMax[N];
vector<int> iMax[N];

int A, B, C, D;
int bestLen = 0;

void relax(int a, int b, int c, int dd)
{
	if (a == -1 || b == -1 || c == -1 || dd == -1)
		return;
	int curLen = d[a][b] + d[b][c] + d[c][dd];
	if (curLen > bestLen)
	{
		bestLen = curLen;
		A = a;
		B = b;
		C = c;
		D = dd;
	}
}

void solve()
{
	for (int i = 0; i < n; i++)
		bfs(i, d[i]);

	for (int i = 0; i < n; i++)
		sMax[i] = iMax[i] = {-1, -1, -1};

	for (int i = 0; i < n; i++)
	{
		for (int s = 0; s < n; s++)
		{
			if (i == s)
				continue;
			if (d[i][s] == INF)
				continue;
			for (int id = 0; id < 3; id++)
			{
				if (sMax[i][id] == -1 || (d[i][sMax[i][id]] <= d[i][s]))
				{
					for (int nid = 2; nid > id; nid--)
						sMax[i][nid] = sMax[i][nid - 1];
					sMax[i][id] = s;
					break;
				}
			}
			for (int id = 0; id < 3; id++)
			{
				if (iMax[s][id] == -1 || (d[iMax[s][id]][s] <= d[i][s]))
				{
					for (int nid = 2; nid > id; nid--)
						iMax[s][nid] = iMax[s][nid - 1];
					iMax[s][id] = i;
					break;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int s = 0; s < n; s++)
		{
			if (i == s)
				continue;
			if (d[i][s] == INF)
				continue;
			for (int a = 0; a < 3 && iMax[i][a] != -1; a++)
				for (int b = 0; b < 3 && sMax[s][b] != -1; b++)
				{
					if (iMax[i][a] != s && iMax[i][a] != sMax[s][b] && 
						sMax[s][b] != i)
						relax(iMax[i][a], i, s, sMax[s][b]);
				}
		}
	}
	printf("%d %d %d %d\n", A + 1, B + 1, C + 1, D + 1);
}

int main()
{
	read();
	solve();
	return 0;
}