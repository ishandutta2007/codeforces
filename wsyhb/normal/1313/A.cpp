#include<bits/stdc++.h>
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
using namespace std;
int dx[10]={0,1,0,0,1,1,0,1},dy[10]={0,0,1,0,1,0,1,1},dz[10]={0,0,0,1,0,1,1,1};
int ans,a,b,c;
void dfs(int now,int x,int y,int z,int tot)
{
	if(now>7)
	{
		if(x<=a&&y<=b&&z<=c) ans=max(ans,tot);
		return;
	}
	dfs(now+1,x+dx[now],y+dy[now],z+dz[now],tot+1);
	dfs(now+1,x,y,z,tot);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		ans=0;
		dfs(1,0,0,0,0);
		printf("%d\n",ans); 
	} 
	return 0;
}