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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 55
char s[N][N];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
bool vis[N][N];
void work()
{
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='B')
			{
				for(int k=0;k<4;k++)
				{
					int tx=i+dx[k],ty=j+dy[k];
					if(tx<1||tx>n||ty<1||ty>m) continue;
					if(s[tx][ty]=='.') s[tx][ty]='#';
				}
			}
		}
	}
	memset(vis,0,sizeof(vis));
	queue<pii> q;
	if(s[n][m]!='#') q.emplace(n,m),vis[n][m]=1;
	while(!q.empty())
	{
		auto [x,y]=q.front(); q.pop();
		for(int i=0;i<4;i++)
		{
			int tx=x+dx[i],ty=y+dy[i];
			if(tx<1||tx>n||ty<1||ty>m) continue;
			if(s[tx][ty]=='#') continue;
			if(vis[tx][ty]) continue;
			vis[tx][ty]=1;
			q.emplace(tx,ty);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='B'&&vis[i][j]) {cout<<"No\n"; return ;}
			if(s[i][j]=='G'&&!vis[i][j]) {cout<<"No\n"; return ;}
		}
	}
	cout<<"Yes\n";
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}