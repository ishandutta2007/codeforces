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
#define N 300005
int sg[N],fa[N],vis[N],n;
vector<int> G[N];
void dfs(int u,int f)
{
	fa[u]=f;
	for(int v:G[u])
	{
		if(v==f) continue;
		dfs(v,u);
		sg[u]^=(sg[v]+1);
	}
}
signed main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	dfs(1,0);
	int ans=sg[1],eg=0;
	if(ans) printf("1");
	else printf("2");
	for(int i=2;i<=n;i++)
	{
		int las=0,u=i;
		while(!vis[u]&&u)
		{
			eg^=1;
			for(int v:G[u])
			{
				if(v==las||v==fa[u]) continue;
				ans^=sg[v]+1;
			}
			vis[u]=1,las=u,u=fa[u];
		}
		if(las) ans^=sg[las]+1;
		if(ans!=eg) printf("1");
		else printf("2");
	}
	return 0;
}