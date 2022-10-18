#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 3005
vector<int> G[N];
int cir[N],fa[N],dep[N],vis[N],rt[N],n,l;
double ans;
void dfs1(int u,int f)
{
	fa[u]=f,vis[u]=1;
	for(int v:G[u])
	{
		if(v==f) continue;
		if(vis[v])
		{
			if(l) continue;
			int tmp=u,s=0;
			while(tmp!=v&&tmp) cir[tmp]=++s,tmp=fa[tmp];
			cir[v]=++s; l=s;
		}
		else dfs1(v,u);
	}
}
void dfs2(int u,int f,int r)
{
	dep[u]=dep[f]+1,rt[u]=r,fa[u]=f;
	for(int v:G[u])
	{
		if(cir[v]||v==f) continue;
		dfs2(v,u,r);
	}
}
int f[N][N];
int lca(int u,int v)
{
	if(rt[u]!=rt[v]) return -1;
	if(u==v) return u;
	if(f[u][v]) return f[u][v];
	if(dep[u]>dep[v]) return lca(fa[u],v);
	else return lca(u,fa[v]);
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int u=read()+1,v=read()+1;
		G[u].pb(v),G[v].pb(u);
	}
	dfs1(1,0);
	// for(int i=1;i<=n;i++) printf("%d%c",cir[i]," \n"[i==n]);
	for(int i=1;i<=n;i++) if(cir[i]) dfs2(i,0,i);
	// for(int i=1;i<=n;i++) printf("%d%c",dep[i]," \n"[i==n]);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
	{
		if(rt[i]!=rt[j])
		{
			int A=dep[i]+dep[j];
			int x=rt[i],y=rt[j];
			int B=abs(cir[x]-cir[y])-1,C=l-2-B;
			// printf("^ %d %d %d %d %d\n",i,j,A,B,C);
			ans+=1.0/(A+B)+1.0/(A+C)-1.0/(A+B+C);
		}
		else
		{
			int L=lca(i,j),D=dep[i]+dep[j]-dep[L]-dep[L]+1;
			// printf("^ %d %d %d\n",i,j,L);
			ans+=1.0/D;
		}
	}
	printf("%.7lf\n",ans);
	return 0;
}