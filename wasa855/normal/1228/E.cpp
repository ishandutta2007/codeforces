#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define mod 1000000007
int qpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
#define N 255
int f[N][N];
int C[N][N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		C[i][0]=1,C[i][i]=1;
		for(int j=1;j<i;j++)
		{
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=i;j++)
//		{
//			printf("%d ",C[i][j]);
//		}
//		cout<<"\n";
//	}
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i][0]=qpow((qpow(k,n)-qpow(k-1,n)+mod)%mod,i);
	}
	for(int i=1;i<=n;i++)
	{
		f[1][i]=qpow(k,n-i);
	}
	for(int r=2;r<=n;r++)
	{
		for(int c=1;c<=n;c++)
		{
			int xx=(qpow(k,n-c)-qpow(k-1,n-c)+mod)%mod*qpow(k-1,c)%mod;
			f[r][c]=xx*f[r-1][c]%mod;
			int tsum=0;
			for(int c0=1;c0<=c;c0++)
			{
				tsum=(tsum+C[c][c0]*qpow(k-1,c-c0)%mod*f[r-1][c-c0])%mod;
			}
			f[r][c]=(f[r][c]+tsum*qpow(k,n-c))%mod;
		}
	}
	cout<<f[n][n]<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}