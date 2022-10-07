#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[400005];
int n,m,x,edgenum,head[200005],pa[200005],pa2[200005],a[200005],b[200005],d[200005],r1,r2;
int st[200005],top,sta[200005],top2,tmp[200005],top3;
bool flag[200005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		if(flag[to])continue;
		pa[to]=node;
		dfs(to);
	}
}
void dfs2(int node)
{
	flag[node]=1;
	sta[++top2]=node;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa2[node])continue;
		if(a[to]==b[to])continue;
		pa2[to]=node;
		dfs2(to);
	}
}
ll solve()
{
//	printf("x=%d\n",x);
	top=0;
	int now=r1;
	ll ans=0;
	while(now!=x)
	{
		st[++top]=now;
		a[now]=a[pa[now]];
		a[now=pa[now]]=0;
		ans++;
	}
//	for(int i=1;i<=n;i++)printf("%d ",a[i]);
//	printf("\n");
//	for(int i=1;i<=n;i++)printf("%d ",b[i]);
//	printf("\n");
	for(int hd=head[x];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[x])continue;
		if(a[to]!=b[to])
		{
			top2=0;
			dfs2(to);
			break;
		}
	}
	int s=0;
	for(int i=1;i<=top2;i++)
	{
		if(a[sta[i]]==b[sta[1]])
		{
			s=i;
			break;
		}
	}
//	printf("%d\n",s);
//	for(int i=1;i<=top2;i++)printf("%d ",a[sta[i]]);
//	printf("\n");
//	for(int i=1;i<=top2;i++)printf("%d ",b[sta[i]]);
//	printf("\n");
	ans+=1ll*(top2+1)*min(s-1,top2-s+1);
	for(int i=top;i>=1;i--)
	{
		a[pa[st[i]]]=a[st[i]];
		a[st[i]]=0;
	}
//	printf("%lld\n",ans);
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(!a[i])r1=i;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		if(!b[i])r2=i;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(r2);
	x=r1;
	while(x!=r2)
	{
		a[x]=a[pa[x]];
		st[++top]=x;
		a[x=pa[x]]=0;
	}
	for(int i=1;i<n;i++)
	{
		int u=e[i*2-1].to;
		int v=e[i*2].to;
		if(a[u]!=b[u]&&a[v]!=b[v])d[u]++,d[v]++;
	}
	int num=0;
	x=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=b[i])
		{
			x=i;
			if(d[i]>2)return puts("-1"),0;
			if(d[i]==1)num++;
			if(d[i]==0)num+=2;
		}
	}
	if(!x)
	{
		printf("0 %d\n",top);
		return 0;
	}
	if(num!=4&&num!=2)return puts("-1"),0;
	while(a[x]!=b[x])x=pa[x];
	int num2=0;
	for(int hd=head[x];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[x])continue;
		if(a[to]!=b[to])num2++;
	}
	if(num==4&&num2!=2)return puts("-1"),0;
	if(num==2&&num2!=1)return puts("-1"),0;
	int u=0,v=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=b[i]&&((d[i]==1&&(num==4?pa[i]!=x:1))||d[i]==0))
		{
			if(!u)u=pa[i]==x&&num==2?x:i;
			else v=pa[i]==x&&num==2?x:i;
		}
	}
	add(u,v);
	add(v,u);
	for(int hd=head[x];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[x])continue;
		if(a[to]!=b[to])
		{
			dfs2(to);
			break;
		}
	}
	int s=0;
	for(int i=1;i<=top2;i++)
	{
		if(a[sta[i]]==b[sta[1]])
		{
			s=i;
			break;
		}
	}
	for(int i=1;i<=top2;i++)
	{
		if(a[sta[(s+i-2)%top2+1]]!=b[sta[i]])
		  return puts("-1"),0;
	}
	printf("%d %d ",min(u,v),max(u,v));
	int now=x;
	while(now!=r2)
	{
		tmp[++top3]=now;
		now=pa[now];
	}
	now=r1;
	while(!flag[now]&&now!=r2)now=pa[now];
	if(now==r2)
	{
		long long ans=top3;
		while(top3)
		{
			int x=tmp[top3--];
			if(x!=st[top])st[++top]=x;
			else top--;
		}
		printf("%lld\n",ans+top+1ll*(top2+1)*min(s-1,top2-s+1));
		return 0;
	}
	for(int i=top;i>=1;i--)
	{
		a[pa[st[i]]]=a[st[i]];
		a[st[i]]=0;
	}
	long long ans=0;
	while(r1!=now)
	{
		a[r1]=a[pa[r1]];
		a[r1=pa[r1]]=0;
		ans++;
	}
	for(int i=top3;i>=1;i--)
	{
		b[pa[tmp[i]]]=b[tmp[i]];
		b[tmp[i]]=0;
		ans++;
	}
	memset(flag,0,sizeof(flag));
	flag[now]=1;
	dfs(r2);
	ll res=1e18;
	for(int hd=head[now];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(pa[to]!=now)
		{
			pa[now]=to;
			res=min(res,ans+solve());
		}
	}
	printf("%lld\n",res);
	return 0;
}