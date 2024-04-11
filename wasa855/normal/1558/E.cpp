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
#define int long long
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
#define N 1005
int a[N],b[N],ok[N],vis[N],n,m,cur;
vector<int> G[N];
bool dfs(int u,int f,int w)
{
	// printf("%d %d %d\n",u,f,w);
	for(int v:G[u]) if(v!=f)
	{
		if(f==0&&ok[v]) continue;
		if(w>a[v])
		{
			if(vis[v]||ok[v]) {cur+=b[u],ok[u]=1; return 1;}
			vis[u]=1;
			int r=dfs(v,u,w+b[v]);
			vis[u]=0;
			// printf("^^ %d %d %d\n",u,v,r);
			if(r) {cur+=(!!f)*b[u],ok[u]=1; return 1;}
		}
	}
	return 0;
}
bool chk(int mid)
{
	for(int i=1;i<=n;i++) vis[i]=ok[i]=0;
	ok[1]=1; cur=mid+b[1];
	while(1)
	{
		bool o=1; for(int i=1;i<=n;i++) o&=ok[i];
		if(o) return 1;
		int hav=0;
		for(int i=1;i<=n;i++) if(ok[i])
		{
			if(dfs(i,0,cur)) {hav=1; break;}
		}
		// cout<<hav<<endl;
		if(!hav) return 0;
	}
}
void work()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=2;i<=n;i++) a[i]=read();
	for(int i=2;i<=n;i++) b[i]=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	int l=a[1]+1,r=inf,ans;
	// int qwq=chk(1);
	// cout<<qwq<<endl;
	// return ;
	while(l<=r)
	{
		int mid=(l+r)/2;
		// printf("%d %d\n",l,r);
		if(chk(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}