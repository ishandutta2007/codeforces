#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

const int N = 100;

int g[N][N];
int deg[N];
bool used[N];
int ans[N][3];
int ind;
        
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
		g[a][b] = g[b][a] = 1;  
		deg[a]++;
		deg[b]++;
		if (deg[a] > 2 || deg[b] > 2)
		{
			puts("-1");
			return 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{	
		if (!used[i] && deg[i] == 2)
		{
			int v[2];
			int li = 0;
			for (int s = 1; s <= n; s++)
			{
				if (g[i][s] == 1)
					v[li++] = s;
			}
			if (g[v[0]][v[1]] == 1)
			{
				ans[ind][0] = i;
				ans[ind][1] = v[0];
				ans[ind][2] = v[1];
				ind++;
			}
			else
			{
				if (deg[v[0]] != 1 || deg[v[1]] != 1)
				{
					puts("-1");
					return 0;
				}
				ans[ind][0] = i;
				ans[ind][1] = v[0];
				ans[ind][2] = v[1];
				ind++;
			}
			used[i] = used[v[0]] = used[v[1]] = 1;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 1 && !used[i])
		{
			int v;
			for (int s = 1; s <= n; s++)
				if (g[i][s] == 1)
					v = s;
			for (int s = 1; s <= n; s++)
			{
				if (deg[s] == 0 && !used[s])
				{
					ans[ind][0] = i;
					ans[ind][1] = v;
					ans[ind][2] = s;
					ind++;                          
					used[i] = used[v] = used[s] = 1;
					break;
				}
			}
		}
	}

	int zero[N];
	int zi = 0;
	for (int i = 1; i <= n; i++)
		if (deg[i] == 0 && !used[i])
			zero[zi++] = i;

	if (zi % 3 != 0)
	{
	 	puts("-1");
	 	return 0;
	}

	for (int i = 0; i < zi; i += 3)
	{
		ans[ind][0] = zero[i];
		ans[ind][1] = zero[i + 1];
		ans[ind][2] = zero[i + 2];
		ind++;
	}
             
    if (ind == n / 3)
    {
    	for (int i = 0; i < ind; i++)
    		cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << endl;
    }

    else
    	puts("-1");
	return 0;
}