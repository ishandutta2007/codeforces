#include <iostream>
#define int long long
#define mod 998244353
using namespace std;
int jc[500005],jcinv[500005],inv[500005];
inline int C(int x,int y)
{
	return jc[x]*jcinv[x-y]%mod*jcinv[y]%mod;
}
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	jc[0]=jc[1]=jcinv[0]=jcinv[1]=inv[1]=1;
	for(int i=2;i<=500000;i++)
	{
		jc[i]=jc[i-1]*i%mod;
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		jcinv[i]=jcinv[i-1]*inv[i]%mod;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if((n-i)%2!=0) continue;
		ans+=C((n-i)/2+i-1,i-1);
	}
	for(int i=1;i<=n;i++) ans=(ans%mod*inv[2])%mod;
	cout << ans;
	return 0;
}