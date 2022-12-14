#include <cstdio>
#include <algorithm>
using namespace std;
#define cs const
#define st static
#define il inline
#define tpl template
#define tpn typename
typedef long long ll;
tpl<tpn T1,tpn T2>il void maxify_il(T1&x,cs T2&y){
	y>x&&(x=y);
}
#define max_n 150000
int a[max_n<<1|1];
int frc[max_n<<1|1];
#define mod 998244353
ll quickpow(ll x,int k){
	ll ret=1;
	for(; k; x=x*x%mod,k>>=1)
		(k&1)&&(ret=ret*x%mod);
	return ret;
}
int main(){
	int n,m;
	scanf("%d",&n);
	int*mid=a+n,*rgt=a+(m=n<<1);
	for(int*i=a; ++i<=rgt; scanf("%d",i));
	nth_element(a+1,mid,rgt+1);
	ll ans=0;
	for(int*i=mid; ++i<=rgt; ans+=*i);
	for(int*i=a; ++i<=mid; ans-=*i);
	ans%=mod,
	frc[0]=1;
	for(ll i=1; i<=m; ++i)
		frc[i]=frc[i-1]*i%mod;
	ll tmp=quickpow(frc[n],mod-2);
	ans=ans*frc[m]%mod*(tmp*tmp%mod)%mod;
	printf("%lld\n",ans);
	return 0;
}