#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
const int N=100+5;
const int C=1e4+5;
int vis[N][N],ans[C];
int main()
{
	int n,m,sx,sy;
	scanf("%d%d%d%d",&n,&m,&sx,&sy);
	for(int i=sy;i<=m;i++) vis[sx][i]=i-sy+1;
	for(int i=1;i<sy;i++) vis[sx][i]=m-sy+1+i;
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(i!=sx)
		{
			cnt++;
			if(cnt&1)
			{
				for(int j=1;j<=m;j++) vis[i][j]=m-vis[sx][j]+1+cnt*m;
			}
			else
			{
				for(int j=1;j<=m;j++) vis[i][j]=vis[sx][j]+cnt*m;
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans[vis[i][j]]=(i-1)*m+j;
	for(int i=1;i<=n*m;i++) printf("%d %d\n",(ans[i]+m-1)/m,(ans[i]-1)%m+1);
	return 0;
}