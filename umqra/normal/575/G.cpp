#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <ctime>
#include <valarray>
#include <complex>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;

const int INF = (int)1e9 + 10;
const int N = (int)1e5 + 10;
struct Edge
{
	int to, len;
	Edge () : to(), len() {}
	Edge (int _to, int _len) : to(_to), len(_len) {}
};

vector <Edge> g[N];
int dist[2][N];
int par[2][N], parLen[2][N];
int listV[N], newV[N];
int q[N];
bool used[N];
int cntV = 0, newCnt;
int n;

void bfs(int st, int *d, int *p, int *pl, int maxLen)
{
	fill(d, d + N, INF);
	int r = 0;
	d[st] = 0;
	q[r++] = st;
	for (int i = 0; i < r; i++)
	{
		int v = q[i];
		for (auto e : g[v])
		{
			int to = e.to;
			int len = e.len;
			if (len <= maxLen && d[to] > d[v] + 1)
			{
				d[to] = d[v] + 1;
				p[to] = v;
				pl[to] = len;
				q[r++] = to;
			}
		}
	}
}

void createStartSet()
{
	int minDist = INF;
	for (int i = 0; i < n; i++)
	{
		if (dist[1][i] != INF)
			minDist = min(minDist, dist[0][i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (dist[1][i] != INF && dist[0][i] == minDist)
		{
			listV[cntV++] = i;
			used[i] = true;
		}
	}
}

void genNextSet()
{
	pair<int, int> bestTo = make_pair(INF, INF);
	for (int i = 0; i < cntV; i++)
	{
		int v = listV[i];
		for (auto e : g[v])
		{
			int to = e.to;
			int len = e.len;
			bestTo = min(bestTo, make_pair(dist[0][to], len));
		}
	}

	newCnt = 0;
	for (int i = 0; i < cntV; i++)
	{
		int v = listV[i];
		for (auto e : g[v])
		{
			int to = e.to;
			int len = e.len;
			if (make_pair(dist[0][to], len) == bestTo && dist[1][to] > dist[1][v] + 1)
			{

				dist[1][to] = dist[1][v] + 1;
				used[to] = true;
				newV[newCnt++] = to;
				par[1][to] = v;
				parLen[1][to] = len;
			}
		}
	}
	for (int i = 0; i < newCnt; i++)
		listV[i] = newV[i];
	cntV = newCnt;
	sort(listV, listV + cntV);
	cntV = unique(listV, listV + cntV) - listV;
}

int ansLen[N];
int ansPath[N];
int pathSize = 0;
int ansSize = 0;
void genLen(int v, int en)
{
	if (v == en)
		return;
	ansLen[ansSize++] = parLen[1][v];
	genLen(par[1][v], en);
}

void genPath(int v, int en)
{
	ansPath[pathSize++] = v;
	if (v != en)
		genPath(par[1][v], en);	
}

void printAnswer(int v, int en)
{
	genLen(v, en);
	while (ansSize > 1 && ansLen[ansSize - 1] == 0)
		ansSize--;
	reverse(ansLen, ansLen + ansSize);
	for (int i = 0; i < ansSize; i++)
		printf("%d", ansLen[i]);
	puts("");
	genPath(v, en);
	printf("%d\n", pathSize);	
	for (int i = 0; i < pathSize; i++)
		printf("%d ", ansPath[i]);
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		g[a].push_back(Edge(b, d));
		g[b].push_back(Edge(a, d));
	}

	bfs(0, dist[0], par[0], parLen[0], 9);
	bfs(n - 1, dist[1], par[1], parLen[1], 0);
	createStartSet();
		
	while (!used[0])
	{
		genNextSet();
	}
	printAnswer(0, n - 1);

	return 0;
}