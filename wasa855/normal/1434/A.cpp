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
#define inf 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 100005
int a[N],b[N],n,m;
int v[N][10];
struct Node
{
	int x,y,val;
	bool operator < (const Node &x) const {return val<x.val;}
};
Node c[N*10];
int pos[N];
signed main()
{
	n=6;
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	m=read();
	for(int i=1;i<=m;i++) b[i]=read();
	int cnt=0,maxn=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=6;j++) v[i][j]=b[i]-a[j];
		sort(v[i]+1,v[i]+7);
		for(int j=1;j<=6;j++) c[++cnt]=(Node){i,j,v[i][j]};
		v[i][7]=inf;
		pos[i]=v[i][1];
		maxn=max(maxn,v[i][1]);
	}
	sort(c+1,c+cnt+1);
	int ans=inf;
	for(int i=1;i<=cnt;i++)
	{
		ans=min(ans,maxn-c[i].val);
		maxn=max(maxn,v[c[i].x][c[i].y+1]);
		if(c[i].y==6) break;
	}
	cout<<ans<<endl;
	return 0;
}