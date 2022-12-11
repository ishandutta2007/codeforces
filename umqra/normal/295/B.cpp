#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
const int N = 501;
int n;

int x[N];
ll g[N][N], gt[N][N];
ll d[N][N];
ll curG[N][N];
bool was[N];
int used[N];
int cc = 1;
ll locD[N];
ll ans[N];
int ind = 0;

void calcD(int v)
{
	cc++;
	for (int i = 0; i < N; i++)	
		locD[i] = (ll)1e18;
	locD[v] = 0;
	while (1)
	{
		int bestV = -1;
		ll minD = (ll)1e18;
		for (int i = 0; i < n; i++)
		{
			if (was[i] && used[i] != cc && locD[i] < minD)
			{
				minD = locD[i];
				bestV = i;
			}
		}
		if (bestV == -1)
			break;
		used[bestV] = cc;
		for (int i = 0; i < n; i++)
			locD[i] = min(locD[i], locD[bestV] + g[bestV][i]);
	}
	for (int i = 0; i < n; i++)
		d[v][i] = locD[i];
}

void calcDT(int v)
{
	cc++;
	for (int i = 0; i < N; i++)	
		locD[i] = (ll)1e18;
	locD[v] = 0;
	while (1)
	{
		int bestV = -1;
		ll minD = (ll)1e18;
		for (int i = 0; i < n; i++)
		{
			if (was[i] && used[i] != cc && locD[i] < minD)
			{
				minD = locD[i];
				bestV = i;
			}
		}
		if (bestV == -1)
			break;
		used[bestV] = cc;
		for (int i = 0; i < n; i++)
			locD[i] = min(locD[i], locD[bestV] + gt[bestV][i]);
	}
	for (int i = 0; i < n; i++)
		d[i][v] = locD[i];
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int s = 0; s < n; s++)
		{
			scanf("%I64d", &g[i][s]);
			gt[s][i] = g[i][s];
		}

	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);

	for (int i = 0; i < n; i++)
		for (int s = 0; s < n; s++)
		{
			curG[i][s] = (ll)1e18;
			d[i][s] = (ll)1e18;
		}
	for (int i = 0; i < n; i++)
	{
		curG[i][i] = 0;
		d[i][i] = 0;
	}


	for (int i = n - 1; i >= 0; i--)
	{   
		ll locAns = 0;
		int v = x[i] - 1;
		was[v] = 1;
		for (int s = 0; s < n; s++)
		{
			curG[v][s] = g[v][s];
			curG[s][v] = g[s][v];
		}
		calcD(v);
		calcDT(v);
		for (int a = 0; a < n; a++)
		{
			if (was[a])
			{
				for (int b = 0; b < n; b++)
				{
					d[a][b] = min(d[a][b], d[a][v] + d[v][b]);
					if (was[b])
						locAns += d[a][b];
				}
			}
		}                          
		ans[ind++] = locAns;
	}

	for (int i = ind - 1; i >= 0; i--)
		printf("%I64d ", ans[i]);

	return 0;
}