#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 20007;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, k, p;
int tab[N];
int mod[N];
int dp[N][52][102];

int main(){
	scanf("%d %d %d", &n, &k, &p);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &tab[i]),
		tab[i] %= p;
	
	for(int i = 0; i < p; ++i)
		mod[i] = i;
	for(int i = p; i < 3 * p; ++i)
		mod[i] = mod[i - p];
	
	for(int i = 0; i <= k; ++i)
		for(int j = 0; j < p; ++j)
			dp[0][i][j] = -MX;
	dp[0][0][0] = 0;

	for(int i = 1; i <= n; ++i){
		for(int t = 0; t < p; ++t)
			dp[i][0][t] = -MX;

		for(int j = 1; j <= k; ++j){
			for(int t = 0; t < p; ++t)
				dp[i][j][t] = dp[i - 1][j][mod[t + p - tab[i]]];
			
			int maxi = -MX;
			for(int t = 0; t < p; ++t)
				maxi = max(maxi, dp[i - 1][j - 1][t] + t);
			dp[i][j][tab[i]] = max(dp[i][j][tab[i]], maxi);
		}
	}
	
/*	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= k; ++j)
			for(int t = 0; t < p; ++t)
				printf("%d %d %d :: %d\n", i, j, t, dp[i][j][t]);
*/	
	int res = 0;
	for(int i = 0; i < p; ++i)
		res = max(res, dp[n][k][i] + i);
	printf("%d\n", res);
	return 0;
}