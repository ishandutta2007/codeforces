#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;
#define N 100005
int n,cnt,head[N],dep[N],num[N],maxx;
struct node
{
	int to,next;
}e[N];
void add(int x,int y)
{
	e[cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt++;
	return ;
}
void dfs(int x,int from)
{
	dep[x]=dep[from]+1;
	num[dep[x]]++;
	maxx=max(dep[x],maxx);
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)
		{
			dfs(to1,x);
		}
	}
	return ;
}
int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		add(x,i+1);
	}
	dfs(1,0);
	int ans=0;
	for(int i=1;i<=maxx;i++)
	{
		ans+=(num[i]&1);
	}
	printf("%d\n",ans);
	return 0;
}