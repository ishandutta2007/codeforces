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
#define N 1005
int n,m;
char s[N][N];
bool vis[N][N];
int dx[]={0,1,-1,0,0};
int dy[]={0,0,0,1,-1};
void dfs(int x,int y)
{
	vis[x][y]=1;
	for(int i=1;i<=4;i++)
	{
		int tx=x+dx[i],ty=y+dy[i];
		if(x<1||x>n||y<1||y>m) continue;
		if(s[tx][ty]=='.') continue;
		if(vis[tx][ty]) continue;
		dfs(tx,ty);
	}
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
	{
		bool ok=0;
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='#')
			{
				if(ok) {cout<<"-1\n"; return 0;}
			}
			else if(s[i][j-1]=='#') ok=1;
		}
	}
	for(int j=1;j<=m;j++)
	{
		bool ok=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i][j]=='#')
			{
				if(ok) {cout<<"-1\n"; return 0;}
			}
			else if(s[i-1][j]=='#') ok=1;
		}
	}
	int ok1=0,ok2=0;
	for(int i=1;i<=n;i++)
	{
		bool ok=0;
		for(int j=1;j<=m;j++) if(s[i][j]=='#') ok=1;
		if(!ok) ok1=1;
	}
	for(int j=1;j<=m;j++)
	{
		bool ok=0;
		for(int i=1;i<=n;i++) if(s[i][j]=='#') ok=1;
		if(!ok) ok2=1;
	}
	if(ok1+ok2==1) {cout<<"-1\n"; return 0;}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='.') continue;
			if(vis[i][j]) continue;
			ans++; dfs(i,j);
		}
	}
	cout<<ans<<endl;
	return 0;
}