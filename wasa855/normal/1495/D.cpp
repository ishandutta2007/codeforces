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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
inline int add(int x,int y) {return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z) {return add(add(x,y),z);}
inline int sub(int x,int y) {return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y) {return 1LL*x*y%mod;}
inline int mul(int x,int y,int z) {return mul(mul(x,y),z);}
#define N 405
int u[N],v[N],ban[N];
vector<int> G[N];
int n,m;
int dgr[N],dep[N][N],fr[N][N];
int fa[N],ch[N];
int find(int u) {return fa[u]==u?u:fa[u]=find(fa[u]);}
int ans[N];
bitset<N> f[N][N];
int res[N][N];
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	for(int i=1;i<=n;i++)
	{
		memset(dep[i],-1,sizeof(dep[i]));
		queue<int> q; q.push(i); dep[i][i]=0;
		while(!q.empty())
		{
			int u=q.front(); q.pop();
			for(int v:G[u])
			{
				if(dep[i][v]==-1) dep[i][v]=dep[i][u]+1,fr[i][v]=u,q.push(v);
			}
		}
		for(int j=1;j<=n;j++) for(int k:G[j]) if(dep[i][j]==dep[i][k]+1) f[i][j][k]=1;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
	{
		if(i>j)
		{
			printf("%d%c",res[j][i]," \n"[j==n]);
			continue;
		}
		memset(ch,0,sizeof(ch));
		int tmp=j; ch[i]=1;
		while(tmp!=i) ch[tmp]=1,tmp=fr[i][tmp];
		int ans=1;
		for(int k=1;k<=n;k++)
		{
			if(ch[k]) continue;
			bitset<N> r=f[i][k]&f[j][k];
			ans=mul(ans,r.count());
		}
		res[i][j]=ans;
		printf("%d%c",ans," \n"[j==n]);
	}
	return 0;
}