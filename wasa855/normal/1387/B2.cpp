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
#define int long long
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
vector<int> G[N];
int siz[N],fa[N];
int n,rt=0,cur=inf;
int sum=0;
void dfs(int u,int f=0)
{
	siz[u]=1;
	int maxn=0;
	for(int v:G[u])
	{
		if(v==f) continue;
		dfs(v,u);
		siz[u]+=siz[v];
		if(siz[v]>maxn) maxn=siz[v];
		sum+=2*min(siz[v],n-siz[v]);
	}
	maxn=max(maxn,n-siz[u]);
	if(maxn<cur) {cur=maxn,rt=u;}
}
vector<int> bel[N];
int B[N];
void dfs2(int u,int f,int id)
{
	bel[id].pb(u);
	B[u]=id;
	for(int v:G[u])
	{
		if(v==f) continue;
		dfs2(v,u,id);
	}
}
struct Node
{
	int v,siz;
	bool operator < (const Node &x) const
	{
		return siz<x.siz;
	}
};
int ans[N];
signed main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	dfs(1);
	priority_queue<Node> q;
	for(int v:G[rt])
	{
		dfs2(v,rt,v);
		q.push((Node){v,bel[v].size()});
	}
	if(n&1)
	{
		while(!q.empty())
		{
			assert(q.size()!=1);
			Node x=q.top(); q.pop();
			Node y=q.top(); q.pop();
			int u=bel[x.v].back(); bel[x.v].pop_back();
			int v=bel[y.v].back(); bel[y.v].pop_back();
			ans[u]=v,ans[v]=u;
			x.siz--,y.siz--;
			if(x.siz) q.push(x);
			if(y.siz) q.push(y);
		}
		int A=G[rt][0],B=ans[A];
		ans[A]=rt,ans[rt]=B,ans[B]=A;
	}
	else
	{
		bel[rt].pb(rt);
		q.push((Node){rt,1});
		while(!q.empty())
		{
			assert(q.size()!=1);
			Node x=q.top(); q.pop();
			Node y=q.top(); q.pop();
			int u=bel[x.v].back(); bel[x.v].pop_back();
			int v=bel[y.v].back(); bel[y.v].pop_back();
			ans[u]=v,ans[v]=u;
			x.siz--,y.siz--;
			if(x.siz) q.push(x);
			if(y.siz) q.push(y);
		}
	}
	cout<<sum<<endl;
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	for(int i=1;i<=n;i++) assert(ans[i]!=0);
	for(int i=1;i<=n;i++) assert(B[i]!=B[ans[i]]);
	return 0;
}