#include<bits/stdc++.h>
#define int long long
const int N=1005;
int n,m,k,a[N][N],s1[N][N],s2[N][N],x,y,ans;
signed main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)scanf("%lld",&a[i][j]);
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)a[i][j]+=a[i-1][j];
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)a[i][j]+=a[i][j-1];
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)s1[i][j]=a[i][j]+s1[i-1][j-1];
	for (int i=n;i>=k;i--)
	 for (int j=k;j<=m;j++)s1[i][j]-=s1[i-k][j-k];
	for (int i=1;i<=n;i++) 
	 for (int j=m;j>=0;j--)s2[i][j]=a[i][j]+s2[i-1][j+1];
	for (int i=n;i>=k;i--)
	 for (int j=0;j<=m-k+1;j++)s2[i][j]-=s2[i-k][j+k];
	for (int i=k;i<=n-k+1;i++)
	 for (int j=k;j<=m-k+1;j++)
	  {
		int val=s2[i+k-1][j]+s2[i-1][j-k]-s1[i+k-1][j-1]-s1[i-1][j+k-1];
		if (val>=ans) ans=val,x=i,y=j;
	 }
	printf("%lld %lld\n",x,y);
}