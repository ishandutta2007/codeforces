#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 200005
struct node{int to,next;}e[N<<1];
int head[N],cnt,out[N],vis[N],ans,n,k,m,del[N],a[N],b[N],s[N];
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++,out[x]++;}
void dfs(int x)
{
	ans--;vis[x]=1;
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		if(del[(i>>1)+1])continue;
		int to1=e[i].to;del[(i>>1)+1]=1;
		if((--out[to1])<k&&!vis[to1])dfs(to1);
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k),ans=n;memset(head,-1,sizeof(head));
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x),a[i]=x,b[i]=y;
	for(int i=1;i<=n;i++)if(out[i]<k&&!vis[i])dfs(i);
	for(int i=m;i;i--)
	{
		s[i]=ans;if(del[i])continue;
		if((--out[a[i]])<k&&!vis[a[i]])dfs(a[i]);
		else if((--out[b[i]])<k&&!vis[b[i]])del[i]=1,dfs(b[i]);del[i]=1;
	}for(int i=1;i<=m;i++)printf("%d\n",s[i]);
}