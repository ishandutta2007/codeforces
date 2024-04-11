#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 210000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL n,a,b;
LL dp[MAXN][2];
char s[MAXN];
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		cin>>n>>a>>b;
		scanf("%s",s);
		//WRT(s);
		RPT(i,0,n+2)
			dp[i][0]=dp[i][1]=LLINF;
		dp[0][0]=b;
		for (int i=1;i<=n;i++)
		{
			if (s[i]=='0' && s[i-1]=='0' || i==n)
			{
				dp[i][0]=min(dp[i][0],dp[i-1][0]+a+b);
				dp[i][0]=min(dp[i][0],dp[i-1][1]+2*a+b);
			}
			dp[i][1]=min(dp[i][1],dp[i-1][0]+2*a+2*b);
			dp[i][1]=min(dp[i][1],dp[i-1][1]+a+2*b);
			//cout<<dp[i][0]<<' '<<dp[i][1]<<endl;
		}
		cout<<dp[n][0]<<endl;
	}
	return ~~(0^_^0);
}