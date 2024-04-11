#include <bits/stdc++.h>
using namespace std;
const int Maxn=300005;
int n,opt[Maxn],rk[Maxn],head[Maxn],cnt,leaf;
struct edg
{
	int nxt,to;
}edge[Maxn];
void add(int x,int y)
{
	edge[++cnt]=(edg){head[x],y};
	head[x]=cnt;
}
void dfs(int u)
{
	int tmp=0x3f3f3f3f;
	if(!head[u])
	{
		leaf++,rk[u]=1;
		return ;
	}
	for(int i=head[u];i;i=edge[i].nxt)
	{ 
		int to=edge[i].to;
		dfs(to);
		if(!opt[u]) rk[u]+=rk[to];
		else tmp=min(tmp,rk[to]);
	}
	if(opt[u]) rk[u]=tmp;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&opt[i]);
	for(int i=2;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		add(x,i);
	}
	dfs(1);
	printf("%d",leaf-rk[1]+1);
	return 0;
}