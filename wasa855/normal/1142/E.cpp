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
#define N 100005
vector<int> G[N],H[N];
int dgr[N],vis[N],used[N];
void dfs(int u,int f)
{
	used[u]=1,vis[u]=1;
	for(int v:G[u])
	{
		if(!vis[v]) H[u].pb(v),dgr[v]++;
		if(!used[v]) dfs(v,u);
	}
	vis[u]=0;
}
int query(int x,int y)
{
	cout<<"? "<<x<<" "<<y<<endl;
	return read();
}
signed main()
{
	int n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		G[u].pb(v);
	}
	for(int i=1;i<=n;i++) if(!used[i]) dfs(i,0);
	queue<int> q;
	for(int i=1;i<=n;i++) if(!dgr[i]) q.push(i);
	while(q.size()>1)
	{
		int u=q.front(); q.pop();
		int v=q.front(); q.pop();
		if(!query(u,v)) swap(u,v);
		for(int V:H[v])
		{
			dgr[V]--;
			if(!dgr[V]) q.push(V);
		}
		q.push(u);
	}
	cout<<"! "<<q.front()<<endl;
	return 0;
}