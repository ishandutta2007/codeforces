#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define max_l 200000
ll quickpow(ll x,int k){
	ll ret=1;
	for(; k; k>>=1,x=x*x%mod)
		(k&1)&&(ret=ret*x%mod);
	return ret;
}
int frc[max_l];
char s[max_l+1];
int main(){
	scanf("%s",s);
	const int l=strlen(s);
	ll now=frc[1]=frc[0]=1;
	for(int i=2; i<l; ++i)
		now=frc[i]=now*i%mod;
	int m=0;
	for(int i=0; i<l; ++i)
		s[i]==')'&&(++m);
	ll ans=0;
	for(int i=0,n=0; m; ++i)
		if(s[i]=='('){
			++n;
			ans=(ans+quickpow(ll(frc[n])*frc[m-1]%mod,mod-2)*frc[n+m-1])%mod;
		}
		else
			--m;
	printf("%lld\n",ans);
	return 0;
}