#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define fir first
#define sec second
#define mod 998244353
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 1000005
int a[N];
vector<int> v[N];
struct Edge
{
	int v,nxt;
};
Edge edge[N*2];
int fir[N],ss;
void add(int u,int v)
{
	edge[++ss]=(Edge){v,fir[u]}; fir[u]=ss;
	edge[++ss]=(Edge){u,fir[v]}; fir[v]=ss;
}
bool vis[N],ans[N];
int dep[N];
ll sum;
void dfs(int u,int f)
{
	dep[u]=dep[f]+1; vis[u]=1;
	if(dep[u]&1) ans[u]=1,sum+=u;
	for(int i=fir[u];i!=0;i=edge[i].nxt)
	{
		int v=edge[i].v;
		if(vis[v]) continue;
		dfs(v,u);
	}
}
signed main()
{
	int n=read();
	if(n%2==0)
	{
		cout<<"First\n";
		for(int i=1;i<=n;i++) printf("%d ",i);
		for(int i=1;i<=n;i++) printf("%d ",i);
		cout<<endl;
	}
	else
	{
		cout<<"Second"<<endl;
		for(int i=1;i<=n*2;i++)
		{
			a[i]=read();
			v[a[i]].pb(i);
		}
		for(int i=1;i<=n;i++) add(i,i+n);
		for(int i=1;i<=n;i++) add(v[i][0],v[i][1]);
		for(int i=1;i<=n;i++) if(!vis[i]) dfs(i,0);
		if(sum%(2*n)==0)
		{
			for(int i=1;i<=n+n;i++) if(ans[i]) printf("%d ",i);
		}
		else
		{
			for(int i=1;i<=n+n;i++) if(!ans[i]) printf("%d ",i);
		}
		cout<<endl;
	}
	return 0;
}