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
#define N 255
int a[N][N],ans[N][N];
signed main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=read();
	set<int> sa,sb;
	for(int i=1;i<=n;i++)
	{
		int x=0;
		for(int j=1;j<=m;j++) if(a[i][j]>x) x=a[i][j];
		sa.insert(x);
	}
	for(int j=1;j<=m;j++)
	{
		int x=0;
		for(int i=1;i<=n;i++) if(a[i][j]>x) x=a[i][j];
		sb.insert(x);
	}
	int x=0,y=0; queue<pii> q;
	for(int i=n*m;i>=1;i--)
	{
		int f=0;
		if(sa.find(i)!=sa.end()) x++,f|=1;
		if(sb.find(i)!=sb.end()) y++,f|=2;
		if(f)
		{
			ans[x][y]=i;
			if(f&1) for(int i=y-1;i>=1;i--) q.emplace(x,i);
			if(f&2) for(int i=x-1;i>=1;i--) q.emplace(i,y);
		}
		else
		{
			auto [x,y]=q.front(); q.pop();
			ans[x][y]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) printf("%d ",ans[i][j]);
		cout<<"\n";
	}
	return 0;
}