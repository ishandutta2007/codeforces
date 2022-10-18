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
inline char rdchar()
{
	char ch=getchar();
	while(!(ch>='a'&&ch<='z')&&!(ch>='A'&&ch<='Z')&&!(ch>='0'&&ch<='9')) ch=getchar();
	return ch;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 105
int n,a[N][N];
int mat[N];
bool vis[N][N];
void work()
{
	memset(a,0,sizeof(a));
	memset(mat,0,sizeof(mat));
	memset(vis,0,sizeof(vis));
	int n=read();
	for(int i=1;i<=n;i++) for(int j=n+1;j<=n+n;j++) a[i][j]=read();
	cout<<"B"<<endl;
	char ch=rdchar(); int nd=read();
	if(ch=='D')
	{
		for(int i=1;i<=n;i++) for(int j=n+1;j<=n+n;j++) a[i][j]=n*n+1-a[i][j];
	}
	if(nd>n)
	{
		for(int i=1;i<=n;i++) for(int j=n+1;j<=n+n;j++) a[i][j]=n*n+1-a[i][j];
	}
	while(1)
	{
		int nd=0,maxn=0;
		for(int i=1;i<=n;i++) if(!mat[i]) nd=i;
		if(!nd) break;
		for(int i=n+1;i<=n+n;i++)
		{
			if(vis[nd][i]) continue;
			if(!maxn||a[nd][i]<a[nd][maxn]) maxn=i;
		}
//		printf("%d %d\n",nd,maxn);
		vis[nd][maxn]=1;
		if(!mat[maxn]||a[mat[maxn]][maxn]<a[nd][maxn])
		{
			mat[mat[maxn]]=0;
			mat[maxn]=nd,mat[nd]=maxn;
		}
	}
//	for(int i=1;i<=n;i++) printf("%d%c",mat[i]," \n"[i==n]);
	cout<<mat[nd]<<endl;
	while(1)
	{
		nd=read();
		if(nd==-2) exit(0);
		if(nd<0) return ;
		cout<<mat[nd]<<endl;
	}
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}