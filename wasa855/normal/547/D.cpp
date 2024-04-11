#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
vector<int> G[N];
int tx[N],ty[N],n;
int ans[N];
void dfs(int u,int col)
{
	ans[u]=col;
	for(int v:G[u])
	{
		if(!ans[v])
		{
			if(col==1) dfs(v,2);
			else dfs(v,1);
		}
	}
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		if(tx[x])
		{
			G[tx[x]].pb(i);
			G[i].pb(tx[x]);
			tx[x]=0;
		}
		else tx[x]=i;
		if(ty[y])
		{
			G[ty[y]].pb(i);
			G[i].pb(ty[y]);
			ty[y]=0;
		}
		else ty[y]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(!ans[i]) dfs(i,1);
	}
	for(int i=1;i<=n;i++) putchar(ans[i]==1?'b':'r');
	return 0;
}