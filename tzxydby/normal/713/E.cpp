#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,k,a[N],b[N],x=1,dp[N],h[N];
vector<int>v;
int chk(int x)
{
	for(int y=1;y<=2;y++)
	{
		dp[y]=(y==1?0:x);
		for(int i=y+1;i<=n;i++)
		{
			dp[i]=dp[i-1];
			if(dp[i-1]>=a[i]-1)
				dp[i]=a[i]+x;
			if(dp[i-1]>=a[i]-x-1)
				dp[i]=max(dp[i],a[i]);
			if(i!=y+1&&dp[i-2]>=a[i]-x-1)
				dp[i]=max(dp[i],a[i-1]+x);
		}
		if(dp[n]>=min(m-1,m+a[y]-x-1))
			return 1;
	}
	return 0;
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		if((b[i%n+1]-b[i]+m)%m>(b[x%n+1]-b[x]+m)%m)
			x=i;
	for(int i=1;i<=n;i++)
	{
		x=x%n+1;
		a[i]=b[x];		
	}
	for(int i=n;i>=1;i--)
		a[i]=(a[i]-a[1]+m)%m;
	int l=-1,r=1000000000;
	while(r-l>1)
	{
		int mid=l+r>>1;
		if(chk(mid))
			r=mid;
		else
			l=mid;
	}
	printf("%d\n",r);
	return 0;
}