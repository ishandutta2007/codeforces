#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 1000000007
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
int f[N][N],sum[N][N];
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++) f[1][i]=1,sum[1][i]=i-1;
	for(int i=2;i<=n;i++)
	{
		f[i][1]=1;
		for(int j=2;j<=m;j++) f[i][j]=add(f[i][j-1],sum[i-1][j]);
		sum[i][2]=f[i][2];
		for(int j=3;j<=m;j++) sum[i][j]=add(sum[i][j-1],f[i][j]);
	}
	// for(int i=1;i<=n;i++)
	// {
		// for(int j=1;j<=m;j++) printf("%d ",f[i][j]);
		// cout<<"\n";
	// }
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			int R=mul(sub(f[i][j],f[i-1][j]),f[n-i+1][j]);
			ans=add(ans,mul(R,m-j+1));
		}
	}
	cout<<ans<<endl;
	return 0;
}