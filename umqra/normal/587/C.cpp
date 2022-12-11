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

const int N = (int)1e5 + 100;
const int LOG = 17;
const int A = 11;
vector <int> g[N];
vector <int> peoples[N];
int jumpP[LOG][N][A];
int jump[LOG][N];
bool used[N];
int h[N];
int tmp[2][A];
int *tmp1 = tmp[0];
int *tmp2 = tmp[1];

void mergeArrays(int *d1, int *d2, int *to)
{
	memset(to, -1, sizeof(*to));
	int it1 = 0, it2 = 0;
	int id = 0;
	while ((d1[it1] != -1 || d2[it2] != -1) && id < A - 1)
	{
		if (d1[it1] == -1 || (d2[it2] != -1 && d2[it2] < d1[it1]))
			to[id++] = d2[it2++];
		else if (d2[it2] == -1 || (d1[it1] != -1 && d1[it1] < d2[it2]))
			to[id++] = d1[it1++];
	}
}

void calcPeoplesJump(int level, int v)
{
	mergeArrays(jumpP[level - 1][v], jumpP[level - 1][jump[level - 1][v]], jumpP[level][v]);
}

void dfs(int v)
{
	for (int i = 0; i < min((int)peoples[v].size(), A - 1); i++)
		jumpP[0][v][i] = peoples[v][i];
	for (int i = 1; i < LOG; i++)
	{
		jump[i][v] = jump[i - 1][jump[i - 1][v]];
		calcPeoplesJump(i, v);
	}
	used[v] = 1;
	for (int to : g[v])
	{
		if (used[to])
			continue;
		jump[0][to] = v;
		h[to] = h[v] + 1;
		dfs(to);
	}
}

int go(int a, int d)
{
	for (int i = 0; i < LOG; i++)
	{
		if (d & (1 << i))
			a = jump[i][a];
	}
	return a;
}

int getLca(int a, int b)
{
	if (h[a] > h[b])
		a = go(a, h[a] - h[b]);
	else
		b = go(b, h[b] - h[a]);
	if (a == b)
		return a;
	for (int i = LOG - 1; i >= 0; i--)
	{
		int na = jump[i][a];
		int nb = jump[i][b];
		if (na != nb)
		{
			a = na;
			b = nb;
		}
	}
	return jump[0][a];
}

void goMerging(int v, int d)
{
	for (int i = 0; i < LOG; i++)
	{
		if (d & (1 << i))
		{
			mergeArrays(tmp1, jumpP[i][v], tmp2);
			swap(tmp1, tmp2);
			v = jump[i][v];
		}
	}
}

void solve(int v, int u)
{
	int c = getLca(v, u);
	memset(tmp, -1, sizeof(tmp));
	goMerging(v, h[v] - h[c] + 1);
	goMerging(u, h[u] - h[c]);
}

int main()
{
	memset(jumpP, -1, sizeof(jumpP));
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	g[0].push_back(1);
	eprintf("Input: done!\n");
	for (int i = 0; i < m; i++)
	{
		int c;
		scanf("%d", &c);
		peoples[c].push_back(i);
	}
	for (int i = 0; i < n; i++)
		sort(peoples[i].begin(), peoples[i].end());

	dfs(0);
	eprintf("Dfs: Done!\n");
	for (int i = 0; i < q; i++)
	{
		int v, u, a;
		scanf("%d%d%d", &v, &u, &a);
		solve(v, u);
		int id = 0;
		while (tmp1[id] != -1)
			id++;
		printf("%d ", min(a, id));
		for (int s = 0; s < min(a, id); s++)
			printf("%d ", tmp1[s] + 1);
		puts("");
	}

	return 0;
}