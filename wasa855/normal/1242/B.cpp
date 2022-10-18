#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 100005
int fa[N];
vector<int> G[N];
bool used[N];
bool vis[N];
int siz[N];
int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		G[u].pb(v);
		G[v].pb(u);
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	int mii=1;
	for(int i=2;i<=n;i++)
	{
		if(G[i].size()<G[mii].size()) mii=i;
	}
	for(int i=0;i<G[mii].size();i++) used[G[mii][i]]=1;
	for(int i=1;i<=n;i++)
	{
		if(!used[i]) fa[find(mii)]=find(i);
		else
		{
			for(int j=0;j<G[i].size();j++) vis[G[i][j]]=1;
			for(int j=1;j<=n;j++) if(!vis[j]) fa[find(i)]=find(j);
			for(int j=0;j<G[i].size();j++) vis[G[i][j]]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		siz[find(i)]++;
	}
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		if(siz[i]!=0) ans++;
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}