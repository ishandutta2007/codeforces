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
#define N 1000005
vector<int> G[N];
int dis[N],col[N],vis[N];
int n,m;
int id(int x)
{
	if(x>n) return x-n;
	return x;
}
signed main()
{
	cin>>n>>m;
	if(n==1)
	{
		printf("0\n0");
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		G[v].pb(u+w*n);
		G[v+n].pb(u+w*n);
	}
	queue<int> q; q.push(n),q.push(n+n);
	vis[n]=vis[n+n]=1;
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int v:G[u])
		{
			if(!vis[id(v)])
			{
				vis[id(v)]=1;
				col[id(v)]=(v>n)^1;
			}
			else if(col[id(v)]!=(v>n)) continue;
			else if(!dis[v]&&v!=n)
			{
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	// for(int i=1;i<=n+n;i++) printf("%d ",dis[i]); cout<<"\n";
	int ans=max(dis[1],dis[n+1]);
	if(!ans) ans=-1;
	cout<<ans<<endl;
	for(int i=1;i<=n;i++) printf("%d",col[i]);
	return 0;
}