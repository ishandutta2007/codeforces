#include<bits/stdc++.h>
using namespace std;
#define pb push_back
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 2000005
int dgr[N];
int u[N],v[N],n;
int fa[N];
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
bool judge(int k)
{
	int r=1<<k;
	for(int i=0;i<r;i++) fa[i]=i,dgr[i]=0;
	for(int i=1;i<=n;i++)
	{
		dgr[u[i]%r]++,dgr[v[i]%r]++;
		fa[find(u[i]%r)]=find(v[i]%r);
	}
	int las=-1;
	for(int i=0;i<r;i++)
	{
		if(dgr[i]&1) return 0;
		if(!dgr[i]) continue;
		if(las==-1) las=find(i);
		else
		{
			if(find(i)!=las) return 0;
		}
	}
	return 1;
}
struct Node
{
	int u,v,id,fr;
	Node(int u=0,int v=0,int id=0,int fr=0):u(u),v(v),id(id),fr(fr){};
};
int qaq;
bool cmp(Node x,Node y)
{
	if(x.id==qaq&&y.id==qaq) return 0;
	if(x.id!=qaq&&y.id!=qaq) return 0;
	if(x.id==qaq) return 0;
	return 1;
}
vector<Node> G[N];
vector<int> ans;
int fir[N];
bool vis[N];
/*
void dfs(int u)
{
	// printf("%d\n",u);
	while(!G[u].empty()&&vis[G[u].back().fr]) G[u].pop_back();
	if(G[u].empty()) return ;
	ans.pb(G[u].back().u),ans.pb(G[u].back().v);
	vis[G[u].back().fr]=1;
	dfs(G[u].back().id);
}
*/
void dfs(int u)
{
	// for(int i=fir[u];i<(int)G[u].size();i++)
	while(fir[u]<(int)G[u].size())
	{
		// printf("%d %d\n",u,fir[u]);
		if(vis[G[u][fir[u]].fr]) {fir[u]++; continue;}
		vis[G[u][fir[u]].fr]=1;
		int A=G[u][fir[u]].v,B=G[u][fir[u]].u;
		fir[u]++;
		dfs(G[u][fir[u]-1].id);
		ans.pb(A),ans.pb(B);
	}
}
void solve(int k)
{
	int r=1<<k;
	for(int i=0;i<r;i++) fa[i]=i,dgr[i]=0;
	for(int i=1;i<=n;i++)
	{
		dgr[u[i]%r]++,dgr[v[i]%r]++;
		// printf("%d %d\n",u[i]%r,v[i]%r);
		G[u[i]%r].emplace_back(i*2-1,i*2,v[i]%r,i);
		G[v[i]%r].emplace_back(i*2,i*2-1,u[i]%r,i);
	}
	for(int i=0;i<r;i++) sort(G[i].begin(),G[i].end(),cmp);
	dfs(u[1]%r);
	for(int i:ans) printf("%d ",i);
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) u[i]=read(),v[i]=read();
	for(int i=20;i>=0;i--)
	{
		if(judge(i))
		{
			cout<<i<<endl;
			solve(i);
			return 0;
		}
	}
	return 0;
}