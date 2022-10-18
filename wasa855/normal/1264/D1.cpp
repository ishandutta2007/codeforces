#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define int long long
#define mod 998244353
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 2005
int f[N][N],g[N][N];
char s[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	scanf("%s",s+1);
	int n=strlen(s+1);
	f[0][0]=1,g[n+1][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(s[i]==')') f[i][j]=f[i-1][j];
			if(s[i]=='(') f[i][j]=f[i-1][j-1];
			if(s[i]=='?') f[i][j]=f[i-1][j]+f[i-1][j-1];
			f[i][j]%=mod;
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++) printf("%lld ",f[i][j]);
//		cout<<"\n";
//	}
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<=n;j++)
		{
			if(s[i]=='(') g[i][j]=g[i+1][j];
			if(s[i]==')') g[i][j]=g[i+1][j-1];
			if(s[i]=='?') g[i][j]=g[i+1][j]+g[i+1][j-1];
			g[i][j]%=mod;
		}
	}
	int ans=0;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ans=(ans+j*f[i][j]%mod*g[i+1][j])%mod;
		}
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}