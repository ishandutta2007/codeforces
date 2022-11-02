#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back
const LL mod= 1000000007;

char C[1000001];
LL dp[1000001][3];

int main()
{
	int n=0;
	LL w=0;
	scanf("%s", C);
	while((int)C[n]!=0) n++;
	dp[0][0]=1;
	dp[0][1]=1;
	for(int i=0; i<n; i++)
	{
		if(C[i]=='?')
		{
			dp[i+1][0]=dp[i][0]+dp[i][2];
			dp[i+1][1]=dp[i][2]+dp[i][0];
			dp[i+1][2]=dp[i][2]+dp[i][1];
			for(int j=0; j<3; j++) dp[i+1][j]%=mod;
		}
		if(C[i]=='*')
		{
			dp[i+1][2]=dp[i][2]+dp[i][1];
			dp[i+1][2]%=mod;
		}
		if(C[i]=='0')
		{
			dp[i+1][0]=dp[i][0];
		}
		if(C[i]=='1')
		{
			dp[i+1][0]=dp[i][2];
			dp[i+1][1]=dp[i][0];
		}
		if(C[i]=='2')
		{
			dp[i+1][1]=dp[i][2];
		}
	}
	if(C[n-1]=='?')
	{
		LL x=(dp[n][0]+dp[n][2])%mod;
		printf("%d\n", (int)x);
	}
	if(C[n-1]=='*') printf("%d\n", (int)dp[n][2]);
	if(C[n-1]=='0' || C[n-1]=='1') printf("%d\n", (int)dp[n][0]);
	if(C[n-1]=='2') printf("0\n");
	return 0;
}