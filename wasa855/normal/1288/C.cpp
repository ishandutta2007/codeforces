#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define int long long
#define mod 1000000007
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 1005
int f[15][N],g[15][N];
int sf[15][N],sg[15][N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	f[0][0]=1;
	for(int i=0;i<=n;i++) sf[0][i]=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++) f[i][j]=sf[i-1][j];
		for(int j=1;j<=n;j++) sf[i][j]=(sf[i][j-1]+f[i][j])%mod;
	}
	g[0][0]=1;
	for(int i=0;i<=n;i++) sg[0][i]=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++) g[i][j]=sg[i-1][j];
		for(int j=n;j>=1;j--) sg[i][j]=(sg[i][j+1]+g[i][j])%mod;
	}
	int ans=0;
//	for(int i=1;i<=n;i++) printf("%lld ",f[m][i]); cout<<"\n";
//	for(int i=1;i<=n;i++) printf("%lld ",g[m][i]); cout<<"\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++) ans=(ans+f[m][i]*g[m][j])%mod;
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}