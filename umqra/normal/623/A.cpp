/*
	Team: Dandelion
	Room: 258
*/

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

const int N = 1000;
int g[N][N];
char str[N];
int deg[N];
int cntV = 0;
int edges = 0;
int n;

void dfs(int v, char letter)
{
	str[v] = letter;
	cntV++;
	for (int i = 0; i < n; i++)
	{
		if (g[v][i] && str[i] != 'b')
			edges++;
		if (str[i] == 0 && g[v][i])
		{
			dfs(i, letter);
		}
	}
}

bool check(int v, char letter)
{
	edges = 0;
	cntV = 0;
	dfs(v, letter);
//	eprintf("%d: %d\n", cntV, edges);
	return edges == cntV * (cntV - 1);
}

int main()
{
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a][b] = g[b][a] = 1;
		deg[a]++;
		deg[b]++;
	}
	for (int i = 0; i < n; i++)
	{
		if (deg[i] == n - 1)
			str[i] = 'b';
	}

	int comps = 0;
	char letter = 'a';
	for (int i = 0; i < n; i++)
	{
		if (str[i] == 0)
		{
			if (!check(i, letter))
			{
				puts("No");
				return 0;
			}
			comps++;
			letter = (letter == 'a' ? 'c' : '?');
		}
	}
	if (comps > 2)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	puts(str);
	return 0;
}