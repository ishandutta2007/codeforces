#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define int long long
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
#define N 30005
int f[55][N];
int pmax[N],smax[N];
int a[55][N],sum[55][N];
int n,m,k;
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) a[i][j]=read();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m+k;j++) sum[i][j]=sum[i][j-1]+a[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) pmax[j]=max(pmax[j-1],f[i-1][j]);
		for(int j=m;j>=1;j--) smax[j]=max(smax[j+1],f[i-1][j]);
		for(int j=1;j<=m;j++)
		{
			int R=smax[j+k];
			if(j-k>=1) R=max(R,pmax[j-k]);
			f[i][j]=R+sum[i][j+k-1]-sum[i][j-1]+sum[i+1][j+k-1]-sum[i+1][j-1];
//			printf("%d %d %d\n",i,j,f[i][j]);
			for(int c=max(1LL,j-k+1);c<=j;c++)
			{
				int R=f[i-1][c];
				R+=sum[i][j+k-1]-sum[i][c+k-1]+sum[i+1][j+k-1]-sum[i+1][j-1];
				if(R>f[i][j]) f[i][j]=R;
			}
			for(int c=j+1;c<=min(m,j+k-1);c++)
			{
				int R=f[i-1][c];
				R+=sum[i][c-1]-sum[i][j-1]+sum[i+1][j+k-1]-sum[i+1][j-1];
				if(R>f[i][j]) f[i][j]=R;
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++) printf("%lld ",f[i][j]);
//		cout<<"\n";
//	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		if(f[n][i]>ans) ans=f[n][i];
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}