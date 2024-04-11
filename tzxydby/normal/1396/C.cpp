#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005;
int n,a[N],dp[N],r1,r2,r3,d,ans,c[N][2],s;
signed main()
{
	cin>>n>>r1>>r2>>r3>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i][0]=r1*a[i]+r3;
		c[i][1]=min(r1*(a[i]+1),r2)+r1;
		dp[i]=min(dp[i-1]+c[i][0],dp[i-1]+c[i][1]+d*2);
		if(i>1)
			dp[i]=min(dp[i],dp[i-2]+c[i-1][1]+c[i][1]+d*2);
	}
	for(int i=n-1;i>=1;i--)
	{
		s+=c[i][1];
		dp[n]=min(dp[n],min(c[n][0],c[n][1]+2*d)+dp[i-1]+s+d*(n-i));
	}
	cout<<dp[n]+d*(n-1)<<endl;
	return 0;
}