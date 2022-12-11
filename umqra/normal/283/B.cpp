#include <algorithm> 
#include <iostream>
#include <vector>
#include <string>        
#include <cstdio>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e6;

ll a[N];
int used[N][2];
bool bad[N][2];
ll val[N][2];
int n;

void dfs(int v, bool st)
{
	used[v][st] = 1;
	val[v][st] = a[v];          
	int newV;
	if (st)
		newV = v + a[v];
	else
		newV = v - a[v];
	if (newV > 0 && newV <= n)
	{
		if (!used[newV][!st])
			dfs(newV, !st);
		else if (used[newV][!st] == 1)
			bad[v][st] = 1;
		if (bad[newV][!st])
			bad[v][st] = 1;
		val[v][st] += val[newV][!st];
	}                 
	used[v][st] = 2;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
                       
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
		scanf("%I64d", &a[i]);

	bad[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (!used[i][0])
			dfs(i, 0);
	}

	for (int i = 1; i <= n - 1; i++)
	{
		int x = 1 + i;
		if (!bad[x][0])
			printf("%I64d\n", val[x][0] + (ll)i);	
		else
			puts("-1");
	}


	return 0;
}