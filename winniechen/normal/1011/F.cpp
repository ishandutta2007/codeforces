#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define N 1000005
#define get(x) (son[fa[x]][0]!=x)
int f[N][2],fa[N],a[N],son[N][2],p[N],n;char s[100];
int dfs(int x)
{
	if(a[x]==1)return p[x];
	if(a[x]==2)
	{
		int tmp=(dfs(son[x][0])&dfs(son[x][1]));
		p[x]=tmp;return tmp;
	}
	if(a[x]==3)
	{
		int tmp=(dfs(son[x][0])|dfs(son[x][1]));
		p[x]=tmp;return tmp;
	}if(a[x]==4)
	{
		int tmp=(dfs(son[x][0])^dfs(son[x][1]));
		p[x]=tmp;return tmp;
	}
	return p[x]=(!dfs(son[x][0]));
}
int get_ans(int x,int now)
{
	if(x==1)return now;
	if(f[x][now]!=-1)return f[x][now];
	int k=get(x),u=fa[x];
	if(a[u]==2)return f[x][now]=get_ans(u,now&p[son[u][!k]]);
	else if(a[u]==3)return f[x][now]=get_ans(u,now|p[son[u][!k]]);
	else if(a[u]==4)return f[x][now]=get_ans(u,now^p[son[u][!k]]);
	return f[x][now]=get_ans(u,!now);
}
int main()
{
	scanf("%d",&n);memset(f,-1,sizeof(f));
	for(int i=1,x,y;i<=n;i++)
	{
		scanf("%s%d",s,&x);
		if(s[0]=='I')p[i]=x,a[i]=1;
		else if(s[0]=='N')a[i]=5,son[i][0]=x,fa[x]=i;
		else
		{
			scanf("%d",&y);fa[x]=i,fa[y]=i;
			son[i][0]=x,son[i][1]=y;
			if(s[0]=='A')a[i]=2;
			else if(s[0]=='X')a[i]=4;
			else a[i]=3;
		}
	}p[1]=dfs(1);
	for(int i=1;i<=n;i++)f[i][p[i]]=p[1];
	for(int i=1;i<=n;i++)if(a[i]==1)printf("%d",get_ans(i,!p[i]));
}