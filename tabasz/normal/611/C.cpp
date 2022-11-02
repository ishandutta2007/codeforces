#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back

bool B[505][505];
int dp[2][505][505];
int n, m, q;
char C[505];

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++)
	{
		scanf("%s", C);
		for(int j=1; j<=m; j++)
		{
			if(C[j-1]=='.')
				B[i][j]=1;
			for(int k=0; k<2; k++)
				dp[k][i][j]=dp[k][i-1][j]+dp[k][i][j-1]-dp[k][i-1][j-1];
			if(B[i][j] && B[i-1][j])
				dp[0][i][j]++;
			if(B[i][j] && B[i][j-1])
				dp[1][i][j]++;
			//printf("%d", dp[1][i][j]);
		}
		//printf("\n");
	}
	scanf("%d", &q);
	for(int i=0; i<q; i++)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int x=0;
		a--;
		b--;
		x+=dp[0][c][d]-dp[0][c][b]-dp[0][a+1][d]+dp[0][a+1][b];
		x+=dp[1][c][d]-dp[1][c][b+1]-dp[1][a][d]+dp[1][a][b+1];
		printf("%d\n", x);
	}
	return 0;
}