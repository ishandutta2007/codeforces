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
#define N 1005
int to[N*4][N],dgr[N],eg[N][N],col[N],id[N];
int n,m,k,cnt;
void dfs(int u,int c1,int c2)
{
	swap(eg[u][c1],eg[u][c2]),swap(to[u][c1],to[u][c2]);
	col[eg[u][c2]]=c2;
	if(to[u][c2]) dfs(to[u][c2],c2,c1);
}
signed main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read()+n;
		int c1=0,c2=0;
		if(dgr[u]%k==0) id[u]=++cnt;
		dgr[u]++,u=id[u];
		if(dgr[v]%k==0) id[v]=++cnt;
		dgr[v]++,v=id[v];
		for(int j=1;j<=k;j++) if(!to[u][j]&&!to[v][j]) {c1=j; break;}
		if(!c1)
		{
			for(int j=1;j<=k;j++) if(!to[u][j]) {c1=j; break;}
			for(int j=1;j<=k;j++) if(!to[v][j]) {c2=j; break;}
			dfs(v,c1,c2);
		}
		to[u][c1]=v,to[v][c1]=u;
		eg[u][c1]=i,eg[v][c1]=i,col[i]=c1;
	}
	for(int i=1;i<=m;i++) printf("%d\n",col[i]);
	return 0;
}