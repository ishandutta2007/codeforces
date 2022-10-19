#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=1e9+7;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;b>>=1;}return ans;}
int n,k,a[N],f[N],ans,r=1,iv;
int main()
{
	scanf("%d%d",&n,&k);
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(int j=i;j;j--)
			f[j]=(1ll*f[j]*a[i]%mod-f[j-1]+mod)%mod;
		f[0]=1ll*f[0]*a[i]%mod;
	}
	iv=qp(n,mod-2);
	for(int i=0;i<=n;i++)
	{
		ans=(ans+1ll*f[i]*r%mod)%mod;
		r=1ll*r*(k-i)%mod*iv%mod;
	}
	ans=(f[0]-ans+mod)%mod;
	printf("%d\n",ans);
	return 0;
}