#include <iostream>
#define mod 998244353
#define int long long
using namespace std;
int jc[200005],jcinv[200005],inv[200005];
inline int C(int x,int y)
{
	return jc[x]*jcinv[y]%mod*jcinv[x-y]%mod;
}
inline int ksm(int x,int y)
{
	int rtn=1;
	while(y)
	{
		if(y&1)
			rtn*=x,rtn%=mod;
		x*=x,x%=mod,y>>=1;
	}
	return rtn;
}
int a[200005];
signed main(int argc, char** argv) {
	int n,k,t=0;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	a[n+1]=a[1];
	for(int i=1;i<=n;i++)
	{
		if(a[i+1]==a[i])
			++t;
	}
	n-=t;
	int ans=ksm(k,n);
	jc[0]=jc[1]=jcinv[0]=inv[1]=jcinv[0]=jcinv[1]=1;
	for(int i=2;i<=200000;i++)
	{
		jc[i]=jc[i-1]*i%mod;
		inv[i]=(mod-mod/i)*(inv[mod%i])%mod;
		jcinv[i]=jcinv[i-1]*inv[i]%mod;
	}
	for(int i=0;i<=n/2;i++)
		ans-=ksm(k-2,n-i*2)*C(n,i)%mod*C(n-i,i)%mod,ans%=mod;
	cout << (ans*inv[2]%mod*ksm(k,t)%mod+mod)%mod;
	return 0;
}