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
#define N 100005
int d[N],t[N],dep[N],res[3];
vector<int> G[N];
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	int cnt=0;
	for(int v:G[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		cnt++;
	}
	if(!cnt) t[fa]++,res[dep[u]%2]++;
}
signed main()
{
	int n=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		d[u]++,d[v]++;
		G[u].pb(v),G[v].pb(u);
	}
	int rt=0;
	for(int i=1;i<=n;i++) if(d[i]>1) rt=i;
	dfs(rt,0);
	if(res[0]&&res[1]) printf("%d ",3);
	else printf("%d ",1);
	int ans=n-1;
	for(int i=1;i<=n;i++)
	{
		if(t[i]) ans-=t[i]-1;
	}
	cout<<ans<<endl;
	return 0;
}