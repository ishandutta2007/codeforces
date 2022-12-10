#pragma region Kek
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<ctime>
#include<cstring>
using namespace std;

#pragma comment(linker, "/STACK:17100500")

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 0
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#pragma endregion

const int N = 2e5 + 10;
int n;
int sz[N], black[N], col[N];
vector<int> edges[N];

void prec(int v, int p)
{
	if (col[v] == 1)
		++black[v];
	sz[v] = 1;
	for(auto e : edges[v])
		if (e != p)
		{
			prec(e, v);
			sz[v] += sz[e];
			black[v] += black[e];
		}
}

void dfs(int v, int p)
{
	if (p != -1)
		col[v] = -col[v];
	printf("%d ", v + 1);
	for(auto e : edges[v])
		if (e != p && black[e] < sz[e])
			dfs(e, v);
	if (p != -1)
	{
		if (col[v] == -1)
			printf("%d %d %d ", p + 1, v + 1, p + 1);
		else
		{
			printf("%d ", p + 1);
			col[p] = -col[p];
		}
		return;
	}
	if (col[v] == 1)
		return;
	auto e = edges[v][0];
	printf("%d %d %d ", e + 1, v + 1, e + 1);
}

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &col[i]);
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	prec(0, -1);
	if (black[0] == sz[0])
	{
		puts("1");
		return;
	}
	dfs(0, -1);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#else
	//freopen(".in", "rt", stdin);
	//freopen(".out", "wt", stdout);
#endif

	solve();

	eprintf("\n\nTime: %.3f\n", clock() * 1. / CLOCKS_PER_SEC);
}