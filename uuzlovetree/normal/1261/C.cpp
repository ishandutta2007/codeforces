#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int n,m;
char str[maxn];
vector<char> a[maxn];
vector<int> c[maxn],sum[maxn];
bool full(int x,int y,int k)
{
	if(x-k<1||y-k<1||x+k>n||y+k>m)return 0;
	int sx=max(1,x-k),sy=max(1,y-k),tx=min(n,x+k),ty=min(m,y+k);
	return sum[tx][ty]-sum[tx][sy-1]-sum[sx-1][ty]+sum[sx-1][sy-1]==(tx-sx+1)*(ty-sy+1);
}
bool check(int k)
{
	for(int i=0;i<=n+1;++i)
		for(int j=0;j<=m+1;++j)c[i][j]=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(full(i,j,k))
			{
				int sx=i-k,sy=j-k,tx=i+k,ty=j+k;
				c[tx+1][ty+1]++;c[sx][ty+1]--;c[tx+1][sy]--;c[sx][sy]++;
			}
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)c[i][j]+=c[i][j-1];
	for(int j=1;j<=m;++j)
		for(int i=1;i<=n;++i)c[i][j]+=c[i-1][j];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(c[i][j]&&a[i][j]=='.')return 0;
			if(!c[i][j]&&a[i][j]=='X')return 0;
		}
	return 1; 
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n+1;++i)a[i].resize(m+2),sum[i].resize(m+2),c[i].resize(m+2);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",str+1);
		for(int j=1;j<=m;++j)a[i][j]=str[j]; 
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)sum[i][j]=(a[i][j]=='X');
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)sum[i][j]+=sum[i][j-1];
	for(int j=1;j<=m;++j)
		for(int i=1;i<=n;++i)sum[i][j]+=sum[i-1][j];
	int l=0,r=max(n,m),ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)printf("%c",full(i,j,ans)?'X':'.');
		puts("");
	}
}