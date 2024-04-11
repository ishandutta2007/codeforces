#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>
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

const int N = 3010;

int dist[5][N];
int q[N];
vector <int> g[N];
const int INF = (int)1e8 + 10;
int n;

void bfs(int st, int id)
{
	fill(dist[id], dist[id] + N, INF);
	dist[id][st] = 0;
	int topQ = 0;
	q[topQ++] = st;
	for (int i = 0; i < topQ; i++)
	{
		int v = q[i];
		for (int to : g[v])
		{
			if (dist[id][to] > dist[id][v] + 1)
			{
				dist[id][to] = dist[id][v] + 1;
				q[topQ++] = to;
			}
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int s1, t1, l1;
	int s2, t2, l2;
	scanf("%d%d%d", &s1, &t1, &l1);
	scanf("%d%d%d", &s2, &t2, &l2);
	s1--, t1--;
	s2--, t2--;

	bfs(s1, 0);
	bfs(t1, 1);

	bfs(s2, 2);
	bfs(t2, 3);

	int answer = INF;
	if (dist[0][t1] <= l1 && dist[2][t2] <= l2)
		answer = dist[0][t1] + dist[2][t2];

	for (int a = 0; a < n; a++)
	{
		bfs(a, 4);
		for (int b = 0; b < n; b++)
		{
			int d1 = dist[0][a] + dist[4][b] + dist[1][b];
			int d2 = dist[2][a] + dist[4][b] + dist[3][b];
			if (d1 <= l1 && d2 <= l2)
				answer = min(answer, d1 + d2 - dist[4][b]);


			d1 = dist[0][a] + dist[4][b] + dist[1][b];
			d2 = dist[3][a] + dist[4][b] + dist[2][b];
			if (d1 <= l1 && d2 <= l2)
				answer = min(answer, d1 + d2 - dist[4][b]);
		}
	}
	if (answer == INF)
		puts("-1");
	else
		cout << m - answer;
	
	return 0;
}