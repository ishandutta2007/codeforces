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
#define N 100005
int n,Q;
vector<pii> G[N];
struct Tree
{
	int fa[N][18],son[N],top[N],dep[N],maxd[N],vis[N],rt;
	int val[N],nd[N],ct,rev[N],col[N],sum[N];
	void dfs1(int u,int f,int fw)
	{
		fa[u][0]=f;
		for(auto [v,w]:G[u])
		{
			if(v==f) continue;
			dfs1(v,u,w);
			if(maxd[v]>maxd[u]) maxd[u]=maxd[v],son[u]=v;
		}
		maxd[u]+=fw;
	}
	void dfs2(int u,int tp)
	{
		top[u]=tp;
		if(!son[u]) return ;
		dfs2(son[u],tp);
		for(auto [v,w]:G[u])
		{
			if(v==fa[u][0]||v==son[u]) continue;
			dfs2(v,v);
		}
	}
	void dfs3(int u,int f)
	{
		if(!col[u]) col[u]=col[f];
		for(auto [v,w]:G[u])
		{
			if(v!=f) dfs3(v,u);
		}
	}
	void init(int RT)
	{
		rt=RT;
		dfs1(rt,0,0),dfs2(rt,rt);
		for(int i=1;i<=n;i++) if(G[i].size()==1&&i!=rt) nd[++ct]=i;
		sort(nd+1,nd+ct+1,[&](int x,int y){return maxd[top[x]]>maxd[top[y]];});
		for(int i=1;i<=ct;i++) col[top[nd[i]]]=i;
		for(int i=1;i<=ct;i++) sum[i]=sum[i-1]+maxd[top[nd[i]]];
		dfs3(rt,0);
		// for(int i=1;i<=n;i++) printf("%d%c",col[i]," \n"[i==n]);
		// cout<<rt<<endl;
		// for(int i=1;i<=n;i++) printf("%d%c",son[i]," \n"[i==n]);
		for(int i=1;i<=17;i++) for(int j=1;j<=n;j++) fa[j][i]=fa[fa[j][i-1]][i-1];
	}
	int query(int x,int y)
	{
		y=min(ct,2*y-1);
		if(col[x]<=y) return sum[y];
		int cur=nd[col[x]],ans=sum[y-1],Ans1=0,Ans2=0;
		while(col[cur]>y)
		{
			Ans1+=maxd[top[cur]]-maxd[son[cur]];
			cur=fa[top[cur]][0];
		}
		int R=maxd[top[nd[y]]]-maxd[son[cur]]+Ans1;
		Ans2=Ans1;
		while(col[cur]>=y)
		{
			Ans2+=maxd[top[cur]]-maxd[son[cur]];
			cur=fa[top[cur]][0];
		}
		ans+=max(Ans2,R);
		// printf("%d - %d %d %d %d %d %d + %d\n",rt,cur,Ans1,Ans2,maxd[top[cur]],maxd[son[cur]],son[cur],ans);
		return ans;
	}
}tr[2];
int Dep[N];
void dfs(int u,int f,int fw)
{
	Dep[u]=Dep[f]+fw;
	for(auto [v,w]:G[u]) if(v!=f) dfs(v,u,w);
}
signed main()
{
	cin>>n>>Q;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		G[u].eb(v,w),G[v].eb(u,w);
	}
	dfs(1,0,0);
	int maxn=0;
	for(int i=1;i<=n;i++) if(Dep[maxn]<Dep[i]) maxn=i;
	tr[0].init(maxn);
	// cout<<maxn<<endl;
	dfs(maxn,0,0);
	maxn=0;
	for(int i=1;i<=n;i++) if(Dep[maxn]<Dep[i]) maxn=i;
	tr[1].init(maxn);
	// cout<<maxn<<endl;
	int las=0;
	while(Q--)
	{
		int x=(read()+las-1)%n+1,y=(read()+las-1)%n+1;
		// printf("%d %d\n",x,y);
		printf("%d\n",las=max(tr[0].query(x,y),tr[1].query(x,y)));
	}
	return 0;
}