#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 200005
#define ll long long 
using namespace std;
struct node{int to,next;}e[N];
int n,ttt[N],v[N],pre[N],vis[N],used[N];
ll ans;
int head[N],q[N],cnt,tot,minn;
void add(int x,int y){e[tot]=(node){y,head[x]};head[x]=tot++;}
void dfs(int x)
{
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(!vis[to1])vis[to1]=-1,dfs(to1);
	}
}
void find(int x) 
{
	minn=1<<30;
	used[x]=1;
	for(int i;;x=i)
	{
		i=ttt[x];
		if(used[i])
		{
			q[0]=i,minn=min(minn,v[i]),vis[i]=-1;
			for(int j=x;j!=i;j=pre[j])q[++cnt]=j,minn=min(minn,v[j]),vis[j]=-1;
			return ;
		}pre[i]=x,used[i]=1;
	}
}
int main()
{
	scanf("%d",&n);memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	for(int i=1;i<=n;i++)scanf("%d",&ttt[i]),add(ttt[i],i);
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			cnt=0;
			find(i);
			ans+=minn;
			for(int i=0;i<=cnt;i++)dfs(q[i]);
		}
	}
	printf("%d",ans);
}