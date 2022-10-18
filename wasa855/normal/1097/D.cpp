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
#define N 10005
inline int qpow(int x,int y)
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
int inv(int x)
{
	return qpow(x,mod-2);
}
int n,k;
int f[55][N],sum[55][N];
int solve(int p,int s)
{
	for(int i=0;i<=s;i++) f[i][0]=qpow(p,i);
	sum[0][0]=f[0][0];
	for(int i=1;i<=s;i++) sum[i][0]=(sum[i-1][0]+f[i][0])%mod;
	for(int j=1;j<=k;j++)
	{
		f[0][j]=1;sum[0][j]=1;
		for(int i=1;i<=s;i++) f[i][j]=sum[i][j-1]*inv(i+1)%mod;
		for(int i=1;i<=s;i++) sum[i][j]=(sum[i-1][j]+f[i][j])%mod;
	}
	return f[s][k];
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n>>k;
	int ans=1;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			int cnt=0;
			while(n%i==0) n/=i,cnt++;
			ans=ans*solve(i,cnt)%mod;
		}
	}
	if(n!=1) ans=ans*solve(n,1)%mod;
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}