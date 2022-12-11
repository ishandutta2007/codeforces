#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = (int)1e5 + 100;

bool used[N];
vector <int> g[N];
int deg[N];

int calcSz(int v)
{
	used[v] = 1;
	int sz = 1;
	for (int i = 0; i < (int)g[v].size(); i++)
	{
		int to = g[v][i];	
		if (!used[to])
			sz += calcSz(to);
	}
	return sz;
}
                             
int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}

	int cnt = calcSz(1);
	if (cnt != n)          
	{                         
		puts("unknown topology");
		return 0;
	}

	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == n - 1)
		{
			if (m == n - 1)
			{
				puts("star topology");
				return 0;
			}
		}
	}
                      
    int cnt1 = 0;
    int cntMore = 0;
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 1) 
			cnt1++;
		if (deg[i] > 2)
			cntMore++;
	}
	if (cntMore == 0 && cnt1 == 0)
	{
		puts("ring topology");
		return 0;
	}

	if (cntMore == 0 && cnt1 == 2)
	{
		puts("bus topology");
		return 0;
	}
                 

	puts("unknown topology");

	return 0;
}