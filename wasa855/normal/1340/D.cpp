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
vector<int> G[N];
int maxn;
vector<pii> ans;
void dfs(int u,int fa,int t)
{
	ans.pb(mp(u,t));
	int x=t;
	for(int v:G[u])
	{
		if(v==fa) continue;
		if(t==maxn) t=maxn-G[u].size(),ans.pb(mp(u,t));
		dfs(v,u,t+1); t++;
		ans.pb(mp(u,t));
	}
	if(fa!=0&&t!=x-1) ans.pb(mp(u,x-1));
}
signed main()
{
	int n=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	for(int i=1;i<=n;i++) if((int)G[i].size()>maxn) maxn=G[i].size();
	dfs(1,0,0);
	cout<<ans.size()<<endl;
	for(pii i:ans) printf("%d %d\n",i.fir,i.sec);
	return 0;
}