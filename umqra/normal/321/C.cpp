#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

const int N = (int)1e5 + 10;
int szV[N];
int par[N];
bool used[N];
vector <int> g[N];
char color[N];           

int dfs(int v, int curPar = -1)
{                      	
	int sz = 1;
	par[v] = curPar;
	for (int i = 0; i < (int)g[v].size(); i++)
	{		
		int to = g[v][i];
		if (to != par[v])
			sz += dfs(to, v);
	}
	return szV[v] = sz;
}

int findRoot(int v, int par, int tSz)
{
	for (int i = 0; i < (int)g[v].size(); i++)
	{	
		int to = g[v][i];
		if (to != par && szV[to] * 2 > tSz)
			return findRoot(to, v, tSz);
	}
	return v;
}
 
void solve(int v, char c)
{                                  
	dfs(v);        
	v = findRoot(v, -1, szV[v]);
	color[v] = c;                                        
	for (int i = 0; i < (int)g[v].size(); i++)
	{	
		int to = g[v][i];    
		g[to].erase(find(g[to].begin(), g[to].end(), v));
		solve(to, c + 1);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
	 	int a, b;
	 	scanf("%d%d", &a, &b);
	 	g[a].push_back(b);	
	 	g[b].push_back(a);
	}

	solve(1, 'A');

	for (int i = 1; i <= n; i++)
		printf("%c ", color[i]);

	return 0;
}