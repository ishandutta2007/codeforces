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

const int N = (int)2e5 + 10;
int n, m;
pii listE[N];

void read()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		listE[i] = mp(a, b);
	}
}

vector <int> g[N];
bool used[N];
int topSort[N];
int pos[N];
int sz = 0;

void dfs(int v)
{
	used[v] = 1;
	for (int to : g[v])
	{
		if (!used[to])
			dfs(to);
	}
	pos[v] = sz;
	topSort[sz++] = v;
}


bool check(int cnt)
{
	for (int i = 0; i < n; i++)
		g[i].clear();
	memset(used, 0, sizeof(used));
	sz = 0;

	for (int i = 0; i < cnt; i++)
	{
		int a, b;
		tie(a, b) = listE[i];
		g[a].push_back(b);
	}
	for (int i = 0; i < n; i++)
	{
		if (!used[i])
			dfs(i);
	}
	for (int i = sz - 1; i >= 1; i--)
	{
		int v = topSort[i];
		int maxPos = -1;
		for (int to : g[v])
		{
			maxPos = max(maxPos, pos[to]);
		}
		if (maxPos != i - 1)
			return false;
	}
	return true;
}

void solve()
{
	int l = 0, r = m;
	while (r - l > 1)
	{
		int mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	if (check(r))
		printf("%d\n", r);
	else
		puts("-1");
}

int main()
{
	read();
	solve();
	return 0;
}