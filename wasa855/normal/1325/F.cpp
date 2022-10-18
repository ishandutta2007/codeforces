#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define INF 0x3fffffff
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 200005
vector<int> G[N];
vector<int> ans[N];
int dep[N],fa[N];
int n,sq,m;
void dfs(int u,int Fa)
{
	dep[u]=dep[Fa]+1,fa[u]=Fa;
	ans[dep[u]%(sq-1)].pb(u);
	for(int v:G[u])
	{
		if(v==Fa) continue;
		if(!dep[v]) dfs(v,u);
		else
		{
			if(dep[u]-dep[v]+1>=sq)
			{
				printf("2\n%d\n",dep[u]-dep[v]+1);
				int cur=u;
				while(cur!=v) printf("%d ",cur),cur=fa[cur];
				printf("%d\n",v);
				exit(0);
			}
		}
	}
}
signed main()
{
	cin>>n>>m;
	while(sq*sq<n) sq++;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	dfs(1,0);
	for(int i=0;i<sq;i++)
	{
		if((int)ans[i].size()>=sq)
		{
			cout<<1<<endl;
			for(int j=0;j<sq;j++) printf("%d ",ans[i][j]);
			cout<<"\n";
			return 0;
		}
	}
	return 0;
}