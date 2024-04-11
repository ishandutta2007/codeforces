#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
#define mod 100000000
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
int f[105][105][2][15];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n1,n2,k1,k2;
	cin>>n1>>n2>>k1>>k2;
	for(int i=0;i<=k1;i++) f[i][0][0][i]=1;
	for(int i=0;i<=k2;i++) f[0][i][1][i]=1;
	for(int i=1;i<=n1;i++)
	{
		for(int j=1;j<=n2;j++)
		{
			for(int k=1;k<=min(i,k1);k++)
			{
				f[i][j][1][1]=(f[i][j][1][1]+f[i][j-1][0][k])%mod;
			}
			for(int k=1;k<=min(j,k2);k++)
			{
				f[i][j][0][1]=(f[i][j][0][1]+f[i-1][j][1][k])%mod;
			}
			for(int k=2;k<=min(i,k1);k++)
			{
				f[i][j][0][k]=(f[i][j][0][k]+f[i-1][j][0][k-1])%mod;
			}
			for(int k=2;k<=min(j,k2);k++)
			{
				f[i][j][1][k]=(f[i][j][1][k]+f[i][j-1][1][k-1])%mod;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=k1;i++) ans=(ans+f[n1][n2][0][i])%mod;
	for(int i=1;i<=k2;i++) ans=(ans+f[n1][n2][1][i])%mod;
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}