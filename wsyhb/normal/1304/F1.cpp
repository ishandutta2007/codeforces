#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int N=50+5,M=2e4+5;
int s[N][M],f[N][M],lmax[N][M],rmax[N][M];
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int x;
			scanf("%d",&x);
			s[i][j]=s[i][j-1]+x;
		}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j+k-1<=m;j++)
		{
			f[i][j]=max(lmax[i-1][max(0,j-k)],rmax[i-1][min(m-k+2,j+k)])+s[i][j+k-1]-s[i][j-1]+s[i+1][j+k-1]-s[i+1][j-1];
			for(int x=max(0,j-k)+1;x<min(m-k+2,j+k);x++)
				f[i][j]=max(f[i][j],f[i-1][x]+s[i][j+k-1]-s[i][j-1]+s[i+1][j+k-1]-s[i+1][j-1]-(i>1?s[i][min(j+k-1,x+k-1)]-s[i][max(j,x)-1]:0));
		}
		for(int j=1;j+k-1<=m;j++) lmax[i][j]=max(lmax[i][j-1],f[i][j]);
		for(int j=m-k+1;j>=1;j--) rmax[i][j]=max(rmax[i][j+1],f[i][j]);
	}
	int ans=0;
	for(int i=1;i+k-1<=m;i++) ans=max(ans,f[n][i]);
	printf("%d",ans);
	return 0;
}