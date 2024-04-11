#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int n,a[N],c[N],dp[N],ans;
int ok(int x,int y)
{
	if(a[x]%a[y]==0&&(c[y]-c[x]==y-x||c[y]<=y-x-1))
		return 1;
	return 0;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		while(a[i]%2==0)
		{
			a[i]/=2;
			c[i]++;
		}
	}
	a[n+1]=1;
	for(int i=n;i>=1;i--)
	{
		dp[i]=n+1;
		for(int j=n+1;j>i;j--)
			if(ok(i,j))
				dp[i]=min(dp[i],dp[j]+j-i-1);
		ans=min(ans,dp[i]+i-1);
	}
	cout<<ans<<endl;
	return 0;
}