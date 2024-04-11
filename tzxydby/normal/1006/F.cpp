#include<bits/stdc++.h>
using namespace std;
const int N=30;
int n,m;
long long a[N][N],k;
map<long long,long long>d[N];
void dfs1(int x,int y,long long v)
{
	if(x>n||y>m)
		return;
	if((x+y)==(n+m)/2+1)
	{
		d[x][v]++;
		return;
	}
	dfs1(x+1,y,v^a[x+1][y]);
	dfs1(x,y+1,v^a[x][y+1]);
}
long long dfs2(int x,int y,long long v)
{
	if(x<1||y<1)
		return 0;
	if(x+y==(n+m)/2+1)
		return d[x][v];
	return dfs2(x-1,y,v^a[x][y])+dfs2(x,y-1,v^a[x][y]);
}
int main()
{
	scanf("%d%d%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%lld",&a[i][j]);
	dfs1(1,1,a[1][1]);
	printf("%lld\n",dfs2(n,m,k));
	return 0;
}