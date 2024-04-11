#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=1000050;
char s[N];
ll dp[N][4];
int main()
{
	int n;
	scanf("%s",s+1);
	n=strlen(s+1);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<4;j++) dp[i][j]=dp[i-1][j];
		if(s[i]=='o')
		{
			dp[i][2]+=dp[i-1][1];
		}
		else if(s[i]=='v' && s[i-1]=='v')
		{
			for(int j=1;j<4;j++) if(j!=2) dp[i][j]+=dp[i-2][j-1];
		}
	}
	printf("%lld\n",dp[n][3]);
	return 0;
}