#include<bits/stdc++.h>
#define inf 1000000000
#define N 505
#define M 500005
using namespace std;
int T,n,m;
char a[155][155];
struct Graph_Match
{
	int Head[N],Next[M],Go[M],Pre[510],Nxt[510],F[510],S[510],Q[510],Vis[510],*Top,Cnt,Tim;
	void init()
	{
		memset(Head,0,sizeof(Head));
		memset(Pre,0,sizeof(Pre));
		memset(Nxt,0,sizeof(Nxt));
		memset(F,0,sizeof(F));
		memset(S,0,sizeof(S));
		memset(Q,0,sizeof(Q));
		memset(Vis,0,sizeof(Vis));
		Top=Q;
		Cnt=Tim=0;
	}
	inline void addedge(int x,int y)
	{
		Go[++Cnt]=y;
		Next[Cnt]=Head[x];
		Head[x]=Cnt;
	}
	int find(int x)
	{
		return x==F[x]?x:F[x]=find(F[x]);
	}
	int lca(int x,int y)
	{
		for(Tim++,x=find(x),y=find(y);;x^=y^=x^=y)
			if(x)
			{
				if(Vis[x]==Tim)return x;
				Vis[x]=Tim;
				x=find(Pre[Nxt[x]]);
			}
	}
	void blossom(int x,int y,int l)
	{
		while(find(x)!=l)
		{
			Pre[x]=y,y=Nxt[x];
			if (S[y]==-1)exit(233);
			S[*Top=y]=0,*Top++;
			if(F[x]==x)F[x]=l;
			if(F[y]==y)F[y]=l;
			x=Pre[y];
		}
	}
	int Match(int n,int x)
	{
		for(int i=1;i<=n;i++)F[i]=i;
		memset(S,-1,sizeof(S));
		S[*(Top=Q)=x]=0,Top++;
		for(int *i=Q;i!=Top;*i++)
			for(int T=Head[*i];T;T=Next[T])
			{
				int g=Go[T];
				if(S[g]==-1)
				{
					Pre[g]=*i,S[g]=1;
					if(!Nxt[g])
					{
						for(int u=g,v=*i,lst;v;u=lst,v=Pre[u])
							lst=Nxt[v],Nxt[v]=u,Nxt[u]=v;
						return 1;
					}
					S[*Top=Nxt[g]]=0,*Top++;
				}
				else if(!S[g]&&find(g)!=find(*i))
				{
					int l=lca(g,*i);
					blossom(g,*i,l);
					blossom(*i,g,l);
				}
			}
		return 0;
	}
	int solve(int n)
	{
		int ans=0;
		for(int i=n;i>=1;--i)if(!Nxt[i])ans+=Match(n,i);
		return ans;
	}
}g;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
    	scanf("%d%d",&n,&m);
    	g.init();
    	for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
    	for(int i=m+1;i<=n+m;++i)g.addedge(i,i+n),g.addedge(i+n,i);
    	for(int i=1;i<=n;++i)
    		for(int j=1;j<=m;++j)
				if(a[i][j]=='1')g.addedge(j,m+i),g.addedge(m+i,j),g.addedge(j,m+i+n),g.addedge(m+i+n,j);
		printf("%d\n",g.solve(n*2+m)-n);
	}
}