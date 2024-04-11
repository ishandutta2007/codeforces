#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
#define N 1000005
#define mod 998244353
int a[N],f[N];
int sum[N];
int tot[N];
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		sum[i]=(sum[i-1]+a[i])%mod;
	}
	int res=0;
//	for(int i=1;i<=n;i++)
//	{
//		sum[i]=(sum[i]+sum[i-1])%mod;
//	}
	for(int i=1;i<=n;i++)
	{
		f[i]=(sum[i]+res+tot[i-1])%mod;
		tot[i]=(tot[i-1]+f[i])%mod;
		res=(res*2+sum[i])%mod;
	}
	cout<<f[n]<<endl;
	return 0;
}