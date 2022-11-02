#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
const int m=1000000007;

int dp[2][1003];
int T[1003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", T+i);
	dp[1][1]=1;
	for(int i=2; i<=n; i++)
	{
			dp[0][i]=(dp[1][i-1]+1)%m;
			dp[1][i]=2*dp[0][i]-dp[0][T[i]]+1;
			if(dp[1][i]<0) dp[1][i]+=m;
			dp[1][i]=dp[1][i]%m;
	}
	printf("%d\n", (dp[1][n]+1)%m);
	return 0;
}