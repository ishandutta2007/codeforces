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
#define N 200005
vector<int> G[N],H[N];
int a[N],b[N];
char res[N];
bool dfs1(int u)
{
	a[u]=1;
	for(int v:G[u])
	{
		if(a[v]==1) return 0;
		if(!a[v])
		{
			if(!dfs1(v)) return 0;
		}
	}
	a[u]=2;
	return 1;
}
bool dfs2(int u)
{
	b[u]=1;
	for(int v:H[u])
	{
		if(b[v]==1) return 0;
		if(!b[v])
		{
			if(!dfs2(v)) return 0;
		}
	}
	b[u]=2;
	return 1;
}
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),H[v].pb(u);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!a[i]&&!b[i]) ans++,res[i]='A';
		else res[i]='E';
		if(!dfs1(i)||!dfs2(i)) {cout<<"-1\n"; return 0;}
	}
	cout<<ans<<endl;
	printf("%s",res+1);
	return 0;
}