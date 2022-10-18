#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define INF 0x3fffffff
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 2005
struct Node
{
	int l,r,p;
};
Node a[N];
bool cmp(Node x,Node y)
{
	return x.p<y.p;
}
int t[N*3],cnt;
int f[N][N*3],g[N*3];
int n;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		a[i]=(Node){x-y,x+y,x};
		t[++cnt]=x-y,t[++cnt]=x+y;
		t[++cnt]=x;
	}
	sort(t+1,t+cnt+1);
	int Q=unique(t+1,t+cnt+1)-t-1;
	for(int i=1;i<=n;i++)
	{
		a[i].l=lower_bound(t+1,t+Q+1,a[i].l)-t;
		a[i].r=lower_bound(t+1,t+Q+1,a[i].r)-t;
		a[i].p=lower_bound(t+1,t+Q+1,a[i].p)-t;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n*3;j++) f[i][j]=f[i-1][j];
		memset(g,0,sizeof(g));
		int x=a[i].p;
		int l=a[i].l,r=a[i].r,p=a[i].p;
		g[x]=f[i-1][l]+t[x]-t[l];
		for(int j=i-1;j>0;j--)
		{
			x=max(x,a[j].r);
			if(f[j-1][l]+t[x]-t[l]>g[x]) g[x]=f[j-1][l]+t[x]-t[l];
		}
		for(int j=Q;j>=l;j--)
		{
			if(g[j]>f[i][j]) f[i][j]=g[j];
			if(g[j]-t[j]+t[j-1]>g[j-1]) g[j-1]=g[j]-t[j]+t[j-1];
		}
		for(int j=p;j<=r;j++)
		{
			if(f[i-1][p]+t[j]-t[p]>f[i][j]) f[i][j]=f[i-1][p]+t[j]-t[p];
		}
		for(int j=1;j<=Q;j++) if(f[i][j-1]>f[i][j]) f[i][j]=f[i][j-1] ;
	}
	cout<<f[n][Q]<<endl;
	return 0;
}