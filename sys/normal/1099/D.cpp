#include <bits/stdc++.h>
using namespace std;
const int Maxn=100005;
int n,s[Maxn],v[Maxn],head[Maxn],id[Maxn],siz[Maxn],ct,cnt;
long long ans;
struct edg
{
	int nxt,to;
}edge[2*Maxn];
void add(int x,int y)
{
	edge[++cnt]=(edg){head[x],y};
	head[x]=cnt;
}
int mini[Maxn];
void init(int u,int fa)
{
	mini[u]=s[u]!=-1?s[u]:0x3f3f3f3f;
	siz[u]=1;
	id[u]=++ct;
//	mini[id[u]][0]=s[u]==-1?0x3f3f3f3f:s[u];
	for(int i=head[u];i;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(to!=fa)
		{
			init(to,u);
			mini[u]=min(mini[u],mini[to]);
			siz[u]+=siz[to];
		}
	}
}
void dfs(int u,int fa,int val)
{
	int _val;
	if(mini[u]==0x3f3f3f3f) return ;
	if(mini[u]>val) ans+=mini[u]-val,_val=mini[u];
	if(_val<s[u]){printf("-1");exit(0);}
	for(int i=head[u];i;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(to!=fa)
			dfs(to,u,_val);
	}
}
int main()
{
	memset(mini,0x3f,sizeof(mini));
//	freopen("D.in","r",stdin);
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
	//	add(i,x);
		add(x,i);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	init(1,0);
	dfs(1,0,0);
	for(int i=1;i<=n;i++)
		ans+=v[i];
	printf("%lld",ans);
	return 0;
}