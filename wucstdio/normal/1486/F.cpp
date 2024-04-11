#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#define ll long long
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[600005];
int n,m,edgenum,head[300005],pa[300005],dfn[300005],sze[300005],st[300005],en[300005],r[300005];
int dep[300005],anc[21][300005],cnt[300005];
ll ans;
set<int>s[300005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int ind;
void dfs1(int node)
{
	dep[node]=dep[pa[node]]+1;
	dfn[node]=++ind;
	sze[node]=1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs1(to);
		sze[node]+=sze[to];
	}
}
void pre()
{
	for(int i=1;i<=n;i++)anc[0][i]=pa[i];
	for(int i=1;i<=20;i++)
	  for(int j=1;j<=n;j++)
	    anc[i][j]=anc[i-1][anc[i-1][j]];
}
int LCA(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=0;dep[u]-dep[v];i++)
	{
		if((1<<i)&(dep[u]-dep[v]))
		  u=anc[i][u];
	}
	if(u==v)return u;
	for(int i=20;i>=0;i--)
	{
		if(anc[i][u]!=anc[i][v])
		{
			u=anc[i][u];
			v=anc[i][v];
		}
	}
	return pa[u];
}
int ti[300005],c2[300005],c3[300005],tmp[300005],top;
int merge(int i,int j)
{
	if(s[i].size()<s[j].size())swap(i,j);
	for(auto x:s[j])
	{
		if(s[i].find(x)!=s[i].end())
		{
			s[i].erase(x);
			tmp[++top]=x;
		}
		else s[i].insert(x);
	}
	return i;
}
void dfs2(int node)
{
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		dfs2(to);
	}
	int o=0;
	ti[++o]=dfn[node];
	c3[o]=(int)s[r[node]].size();
//	printf("start %lld\n",ans);
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		ti[++o]=dfn[to];
		cnt[node]+=cnt[to];
		c3[o]=(int)s[r[to]].size();
//		printf("c3=%d\n",c3[o]);
		ans-=1ll*s[r[to]].size()*(s[r[to]].size()-1)/2;
		top=0;
		r[node]=merge(r[node],r[to]);
		for(int i=1;i<=top;i++)
		{
			int l=1,r=o-1;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(st[tmp[i]]<ti[mid])r=mid-1;
				else l=mid+1;
			}
//			printf("%d,r=%d\n",tmp[i],r);
			if(r!=1)ans+=c2[r];
			c2[r]++;
			c3[r]--;
			c3[o]--;
			tmp[i]=r;
		}
//		printf("c2:");
//		for(int i=1;i<=o;i++)printf("%d ",c2[i]);
//		printf("\n");
		for(int i=1;i<=top;i++)c2[tmp[i]]=0;
		top=0;
//		printf("ans=%lld\n",ans);
	}
	for(int i=2;i<=o;i++)ans+=1ll*c3[i]*(c3[i]-1)/2;
//	printf("%d %lld\n",(int)s[r[node]].size(),ans);
	ans+=1ll*cnt[node]*(cnt[node]-1)/2;
	ans-=1ll*s[r[node]].size()*(s[r[node]].size()-1)/2;
//	printf("node=%d, ans=%lld\n",node,ans);
}
int u[300005],num;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs1(1);
	pre();
	for(int i=1;i<=n;i++)r[i]=i;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==y)
		{
			u[++num]=x;
			m--;
			i--;
			continue;
		}
		if(dfn[x]>dfn[y])swap(x,y);
		int d=LCA(x,y);
		cnt[x]++,cnt[y]++;
		cnt[d]--,cnt[pa[d]]--;
		st[i]=dfn[x],en[i]=dfn[y];
//		printf("%d [%d,%d]\n",i,st[i],en[i]);
		s[r[x]].insert(i);
		s[r[y]].insert(i);
	}
	dfs2(1);
	for(int i=1;i<=num;i++)
	{
		ans+=cnt[u[i]];
		cnt[u[i]]++;
	}
	printf("%lld\n",ans);
	return 0;
}