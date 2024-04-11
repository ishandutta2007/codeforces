#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int N = 200;

int a[N], x[N], y[N];
int d[N];
bool used[N];
int dist[N][N];
int n, D;

bool check(int m)
{
	fill(d, d + N, -1);
	fill(used, used + N, 0);
	d[0] = m;
	while (1)
	{
		int curD = -1, v;
		for (int i = 0; i < n; i++)
		{
			if (!used[i] && d[i] > curD)
			{
				curD = d[i];
				v = i;
			}
		}
		if (curD == -1)
			break;                       
		used[v] = 1;                      
		for (int s = 0; s < n; s++)
		{
			if (!used[s] && curD - dist[v][s] * D >= 0)
				d[s] = max(d[s], curD - dist[v][s] * D + a[s]);
		}
	}
	if (used[n - 1])
		return true;
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
           
	cin >> n >> D;
	for (int i = 1; i < n - 1; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
         

	for (int i = 0; i < n; i++)
	{
		for (int s = 0; s < n; s++)
			dist[i][s] = abs(x[i] - x[s]) + abs(y[i] - y[s]);
	}

	int l = 0, r = (int)1e8; 
	while (r - l > 1)
	{
		int m = (l + r) / 2;
		if (check(m))
			r = m;
		else
			l = m;
	}

	printf("%d", r);

	return 0;
}