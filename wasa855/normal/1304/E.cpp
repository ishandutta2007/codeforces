#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;

#define N 100005
int n;
struct Edge
{
    int v,nxt;
};
Edge edge[N*2];
int fir[N],ss;
void add(int u,int v)
{
    ss++;
    edge[ss].v=v;
    edge[ss].nxt=fir[u];
    fir[u]=ss;
    ss++;
    edge[ss].v=u;
    edge[ss].nxt=fir[v];
    fir[v]=ss;
}
int siz[N],son[N];
int top[N],fa[N],dep[N];
void dfs1(int u,int Fa)
{
    siz[u]=1;fa[u]=Fa;dep[u]=dep[Fa]+1;
    for(int i=fir[u];i!=0;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(v==Fa) continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]]) son[u]=v;
    }
}
void dfs2(int u,int topf)
{
    top[u]=topf;
    if(!son[u]) return ;
    dfs2(son[u],topf);
    for(int i=fir[u];i!=0;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}
int lca(int u,int v)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]>dep[top[v]]) u=fa[top[u]];
        else v=fa[top[v]];
    }
    return dep[u]>dep[v]?v:u;
}
int dis(int u,int v)
{
	int x=lca(u,v);
	return dep[u]+dep[v]-dep[x]*2;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v);
	}
	dfs1(1,0),dfs2(1,1);
	int Q=read();
	while(Q--)
	{
		int x=read(),y=read(),a=read(),b=read(),k=read();
		int be=dis(a,b);
		if(k>=be&&k%2==be%2)
		{
			printf("YES\n");
			continue;
		}
		int R=dis(a,x)+dis(b,y)+1;
		if(k>=R&&k%2==R%2)
		{
			printf("YES\n");
			continue;
		}
		R=dis(a,y)+dis(b,x)+1;
		if(k>=R&&k%2==R%2)
		{
			printf("YES\n");
			continue;
		}
		printf("NO\n");
	}
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}