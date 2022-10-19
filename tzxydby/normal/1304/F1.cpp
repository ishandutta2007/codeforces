#include<bits/stdc++.h>
using namespace std;
const int N=55,M=20005;
int n,m,k,a[N][M],s[N][M],dp[N][M],ar[M],tr[M<<2],tag[M<<2];
void pushup(int k)
{
	tr[k]=max(tr[k<<1],tr[k<<1|1]);
}
void pushdown(int k)
{
	tr[k<<1]+=tag[k];
	tag[k<<1]+=tag[k];
	tr[k<<1|1]+=tag[k];
	tag[k<<1|1]+=tag[k];
	tag[k]=0;
}
void build(int k,int l,int r)
{
	tag[k]=0;
	if(l==r)
	{
		tr[k]=ar[l];
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
}
void update(int k,int l,int r,int a,int b,int v)
{
	if(l==a&&r==b)
	{
		tr[k]+=v;
		tag[k]+=v;
		return;
	}
	pushdown(k);
	int mid=l+r>>1;
	if(b<=mid) update(k<<1,l,mid,a,b,v);
	else if(a>mid) update(k<<1|1,mid+1,r,a,b,v);
	else update(k<<1,l,mid,a,mid,v),update(k<<1|1,mid+1,r,mid+1,b,v);
	pushup(k);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			s[i][j]=s[i][j-1]+a[i][j];
		}
	}
	for(int j=1;j<=m-k+1;j++)
		dp[1][j]=s[1][j+k-1]-s[1][j-1]+s[2][j+k-1]-s[2][j-1];
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			ar[j]=dp[i-1][j];
		build(1,1,m);
		for(int j=1;j<=k;j++)
			update(1,1,m,1,j,-a[i][j]);
		for(int j=1;j<=m-k+1;j++)
		{
			dp[i][j]=tr[1]+s[i+1][j+k-1]-s[i+1][j-1]+s[i][j+k-1]-s[i][j-1];
			if(j==m-k+1)
				break;
			update(1,1,m,max(1,j-k+1),j,a[i][j]);
			update(1,1,m,j+1,j+k,-a[i][j+k]);
		}
	}
	int ans=0;
	for(int j=1;j<=m-k+1;j++)
		ans=max(ans,dp[n][j]);
	printf("%d\n",ans);
	return 0;
}