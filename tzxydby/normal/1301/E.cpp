#include<bits/stdc++.h>
using namespace std;
const int N=502;
char s[N][N];
int n,m,q,sum[N][N][4],a[N][N][N/2];
int query(int x1,int y1,int x2,int y2,int k){return sum[x2][y2][k]-sum[x1-1][y2][k]-sum[x2][y1-1][k]+sum[x1-1][y1-1][k];}
int zh(int x1,int y1,int x2,int y2,int k){return a[x2][y2][k]-a[x1-1][y2][k]-a[x2][y1-1][k]+a[x1-1][y1-1][k];}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='R')
				sum[i][j][0]=1;
			if(s[i][j]=='G')
				sum[i][j][1]=1;
			if(s[i][j]=='Y')
				sum[i][j][2]=1;
			if(s[i][j]=='B')
				sum[i][j][3]=1;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<4;k++)
				sum[i][j][k]+=sum[i-1][j][k]+sum[i][j-1][k]-sum[i-1][j-1][k];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;;k++)
			{
				int x1=i+k-1,x2=x1+k,y1=j+k-1,y2=y1+k;
				if(x2>n||y2>m)
					break;
				if(query(i,j,x1,y1,0)==k*k&&query(i,y1+1,x1,y2,1)==k*k&&query(x1+1,j,x2,y1,2)==k*k&&query(x1+1,y1+1,x2,y2,3)==k*k)
				{
					a[i][j][k]=1;
					break;
				}
			}
		}
	}
	for(int k=1;k<=n/2;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				a[i][j][k]+=a[i-1][j][k]+a[i][j-1][k]-a[i-1][j-1][k];
	while(q--)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int ans=0;
		for(int k=250;k>=1;k--)
		{
			int x=x2-2*k+1,y=y2-2*k+1;
			if(x<x1||y<y1)
				continue;
			if(zh(x1,y1,x,y,k))
			{
				ans=k;
				break;
			}
		}
		printf("%d\n",ans*ans*4);
	}
	return 0;
}