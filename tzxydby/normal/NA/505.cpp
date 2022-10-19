#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,a[N],b[N],dp[N][2],c[N],d[N];
int sol(int l,int r,int i)
{
	if(l>r)
		return 0;
	int ans=r-l,p=lower_bound(a+l,a+r+1,b[i])-a;
	if(l+1<=p&&p<=r&&a[p]-b[i]==b[i]-a[p-1])
		ans--;
	return ans;
}
int main()
{
	scanf("%d%d%*d%*d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		int p=lower_bound(b+1,b+m+1,a[i])-b;
		if(p>m)
			c[m]=i;
		else if(p>1)
		{
			if(a[i]-b[p-1]<b[p]-a[i])
				c[p-1]=i;
			else if(a[i]-b[p-1]==b[p]-a[i])
				d[p-1]++,c[p]=i;
			else
				c[p]=i;
		}
		else
			c[1]=i;
	}
	for(int i=1;i<=m;i++)
		c[i]=max(c[i],c[i-1]);
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=d[i];j++)
		{
			dp[i][j]=1e9;
			for(int k=0;k<=d[i-1];k++)
				dp[i][j]=min(dp[i][j],dp[i-1][k]+sol(c[i-1]+1+k,c[i]+j,i));
		}
	}
	printf("%d\n",dp[m][0]);
	return 0;
}