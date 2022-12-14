#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <cstdlib>
using namespace std;
#define N 40
#define ll long long
ll l,r;
int vis[N][N],ans;
void dfs(int x,int y,ll num)
{
	if(vis[x][y])return ;
	if(!vis[x][y])vis[x][y]=1;
	if(num>=l&&num<=r)ans++;
	if(num>r)return ;
	dfs(x+1,y,num*2);
	dfs(x,y+1,num*3);
}
int main()
{
	scanf("%I64d%I64d",&l,&r);
	dfs(0,0,1);
	printf("%d\n",ans);
	return 0;
}