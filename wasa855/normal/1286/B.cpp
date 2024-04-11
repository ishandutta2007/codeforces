#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 2005
vector<int> G[N];
bool used[N];
int siz[N],c[N];
int res[N];
int n;
void dfs1(int u)
{
	siz[u]=1;
	for(int v:G[u])
	{
		dfs1(v); siz[u]+=siz[v];
	}
}
void dfs2(int u)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!used[i]) cnt++;
		if(cnt==c[u]+1)
		{
			res[u]=i;
			break;
		}
	}
	used[res[u]]=1;
	for(int v:G[u]) dfs2(v);
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	n=read();
	int rt;
	for(int i=1;i<=n;i++)
	{
		int p=read();c[i]=read();
		if(p) G[p].pb(i);
		else rt=i;
	}
	dfs1(rt);
	for(int i=1;i<=n;i++)
	{
		if(c[i]>=siz[i])
		{
			cout<<"NO\n";
			return 0;
		}
	}
	dfs2(rt);
	cout<<"YES\n";
	for(int i=1;i<=n;i++) printf("%d ",res[i]);
	cout<<"\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}