#include<bits/stdc++.h>
using namespace std;
const int N=1000005,mod=1000000007;
int qp(int a,int b)
{
	if(b<0)
		return 0;
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int n,m,v[N],f[N],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		v[x]++;
		m=max(m,x);
	}
	for(int i=m;i>=2;i--)
	{
		int s=0;
		for(int j=i;j<=m;j+=i)
		{
			f[i]=(f[i]+mod-f[j])%mod;
			s+=v[j];
		}
		f[i]=(f[i]+1ll*s*qp(2,s-1)%mod)%mod;
		ans=(ans+1ll*i*f[i])%mod;
	}
	printf("%d\n",ans);
	return 0;
}