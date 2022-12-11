#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 320;
const long long INF = (long long)1e17;
long long dp[N][N];
long long g[N][N];

int main()
{

    for (int i = 0; i < N; i++)
    	for (int s = 0; s < N; s++)
    		g[i][s] = dp[i][s] = INF;

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++)
	{
		int l, r, c;
		scanf("%d%d%d", &l, &r, &c);
		for (int s = l; s <= r; s++)
			g[l][s] = min(g[l][s], (long long)c);
	}
            
	for (int i = 0; i < N; i++)
		dp[i][0] = 0;
	
	for (int i = 1; i <= n; i++)
	{
		for (int s = 1; s <= i; s++)
		{
			dp[i][s] = dp[i - 1][s];
			for (int q = i - s + 1; q <= i; q++)
				dp[i][s] = min(dp[i][s], dp[q - 1][s - (i - q + 1)] + g[q][i]);
		}
	}
                        
	long long ans = INF;
	for (int i = k; i <= n; i++)
		ans = min(dp[n][k], ans);
    if (ans == INF)
    	cout << -1;
    else
    	cout << ans;
	return 0;
}