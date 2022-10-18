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
#define N 2025
int f[N][N],pre[N][N],n,m;
void init()
{
	for(int i=1;i<=max(n,m);i++) f[1][i]=1,pre[1][i]=i;
	for(int i=2;i<=max(n,m);i++)
	{
		for(int j=1;j<=max(n,m);j++) f[i][j]=pre[i-1][j];
		for(int j=1;j<=max(n,m);j++) pre[i][j]=add(pre[i][j-1],f[i][j]);
	}
}
int g[N],h[N];
signed main()
{
	cin>>n>>m;
	init();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) g[j]=mul(f[i][m-j+1],pre[i][j]);
		for(int j=1;j<=m;j++) h[j]=mul(f[n-i][j],pre[n-i][m-j+1]);
		int cur=0;
		for(int j=1;j<=m;j++)
		{
			ans=add(ans,mul(h[j],cur));
			cur=add(cur,g[j]);
		}
		for(int j=1;j<m;j++) ans=sub(ans,mul(g[j],h[j+1]));
	}
	swap(n,m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) g[j]=mul(f[i][m-j+1],pre[i][j]);
		for(int j=1;j<=m;j++) h[j]=mul(f[n-i][j],pre[n-i][m-j+1]);
		int cur=0;
		for(int j=1;j<=m;j++)
		{
			ans=add(ans,mul(h[j],cur));
			cur=add(cur,g[j]);
		}
	}
	swap(n,m);
	cout<<add(ans,ans)<<endl;
	return 0;
}