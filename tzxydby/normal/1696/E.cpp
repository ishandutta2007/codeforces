#include<bits/stdc++.h>
using namespace std;
const int N=600005,mx=600000,mod=1e9+7;
int n,a[N],fc[N],iv[N],s;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;b>>=1;}return ans;}
int c(int n,int m){return 1ll*fc[n]*iv[m]%mod*iv[n-m]%mod;}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
		scanf("%d",&a[i]);
	fc[0]=1;
	for(int i=1;i<=mx;i++)
		fc[i]=1ll*fc[i-1]*i%mod;
	iv[mx]=qp(fc[mx],mod-2);
	for(int i=mx-1;i>=0;i--)
		iv[i]=1ll*iv[i+1]*(i+1)%mod;
	for(int i=0;i<=n;i++)
		s=(s+c(i+a[i],i+1))%mod;
	printf("%d\n",s);
	return 0;
}