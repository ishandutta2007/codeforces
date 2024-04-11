#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int mod=998244353;
template<int mod=::mod>ll quickpow(ll x,int k,ll ret=1){
	for(; k; k>>=1,x=x*x%mod)
		(k&1)&&(ret=ret*x%mod);
	return ret;
}
constexpr int max_n=300000;
int f[max_n+1],fac[max_n+1],ifac[max_n+1];
void test(){
	int n;
	scanf("%d",&n);
	f[0]=1,f[1]=1;
	for(int i=2; i<=n; ++i)
		f[i]=(ll(i-1)*f[i-2]+f[i-1])%mod;
	ll now=fac[0]=1;
	for(int i=1; i<=n; ++i)
		fac[i]=now=now*i%mod;
	ifac[n]=now=quickpow(now,mod-2);
	for(int i=n; i; ifac[--i]=now)
		now=now*i%mod;
	int ans=0;
	for(int i=0; i*4<=n; ++i)
		ans=(ans+ll(fac[n-i*2])*ifac[n-i*4]%mod*ifac[i]%mod*f[n-i*4])%mod;
	printf("%d\n",ans);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}