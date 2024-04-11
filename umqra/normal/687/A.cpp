#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <algorithm>

#include <valarray>
#include <complex>
#include <functional>
#include <cassert>

using namespace std;
typedef long long ll;

int n, m;

const int N = (int)2e5 + 10;
vector <int> g[N];

void read()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;	
		g[a].push_back(b);
		g[b].push_back(a);
	}
}

vector <int> res[2];
int color[N];

bool paint(int v, int c)
{
	color[v] = c;
	int nc = (c == 1 ? 2 : 1);
	for (int to : g[v])
	{
		if (color[to] == 0)
		{
			if (!paint(to, nc))
				return false;
		}
		else if (color[to] != nc)
			return false;
	}
	return true;
}

void fail()
{
	puts("-1");
	exit(0);
}

void solve()
{
	for (int i = 0; i < n; i++)
	{
		if (color[i] == 0)
		{
			if (!paint(i, 1))
			{
				fail();
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		res[color[i] - 1].push_back(i + 1);	
	}
	printf("%d\n", (int)res[0].size());
	for (int x : res[0])
		printf("%d ", x);
	puts("");
	printf("%d\n", (int)res[1].size());
	for (int x : res[1])
		printf("%d ", x);
	puts("");
}


int main()
{
	read();
	solve();
    return 0;
}