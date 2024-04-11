#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
#define N 200005
vector<int> G[N];
bool vis[N];
int maxn=0;
void dfs(int u)
{
	if(u>maxn) maxn=u;
	vis[u]=1;
	for(int v:G[u])
	{
		if(!vis[v]) dfs(v);
	}
}
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
		G[u].pb(v),G[v].pb(u);
	}
	for(int i=1;i<=n;i++) sort(G[i].begin(),G[i].end());
	int ans=0,cur=1;
	for(int i=1;i<=n;i++)
	{
		if(G[i].size()==0) continue;
		if(vis[i]) continue;
		dfs(i);
		cur=max(cur,i);
		for(int i=cur+1;i<=maxn;i++)
		{
			if(!vis[i])
			{
				ans++;
				G[i-1].pb(i),G[i].pb(i-1);
				dfs(i);
			}
		}
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}