#include<bits/stdc++.h>
#define maxn 305
using namespace std;
int n;
int t[maxn];
bool vis[maxn][maxn][8][31],vis2[maxn][maxn];
const int dx[]={1,1,0,-1,-1,-1,0,1};
const int dy[]={0,1,1,1,0,-1,-1,-1};
void dfs(int x,int y,int k,int sta)
{
	if(vis[x][y][k][sta])return;
	vis[x][y][k][sta]=1;
	for(int i=0;i<t[sta];++i)vis2[x+i*dx[k]][y+i*dy[k]]=1;
	int nx=x+(t[sta]-1)*dx[k],ny=y+(t[sta]-1)*dy[k];
	if(sta==n)return;
	dfs(nx+dx[(k+1)%8],ny+dy[(k+1)%8],(k+1)%8,sta+1);
	dfs(nx+dx[(k+7)%8],ny+dy[(k+7)%8],(k+7)%8,sta+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&t[i]);
	dfs(151,151,2,1);
	int ans=0;
	for(int i=1;i<=302;++i)
		for(int j=1;j<=302;++j)if(vis2[i][j])ans++;
	printf("%d\n",ans);
	return 0;
}