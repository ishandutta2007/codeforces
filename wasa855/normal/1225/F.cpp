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
vector<int> G[N],t,ans;
int p[N];
int dep[N];
void dfs1(int u)
{
	dep[u]=1;
	int id=0;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		dfs1(v);
		if(dep[v]+1>dep[u]) dep[u]=dep[v]+1,id=i;
	}
	if(G[u].size()) swap(G[u][G[u].size()-1],G[u][id]);
}
void dfs2(int u)
{
	t.pb(u);
	for(int v:G[u])
	{
		int now=t.back();
		while(now!=u)
		{
			ans.pb(v),now=p[now];
		}
		dfs2(v);
	}
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<n;i++) p[i]=read(),G[p[i]].pb(i);
	dfs1(0);
	dfs2(0);
	for(int i=0;i<n;i++) printf("%d ",t[i]);
	cout<<"\n";
	cout<<ans.size()<<endl;
	for(int x:ans) printf("%d ",x);
	cout<<"\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}