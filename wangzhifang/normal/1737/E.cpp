#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr int mod=1000000007;
constexpr int iv2=(mod+1)/2;
template<int mod=::mod>ll quickpow(ll x,int k,ll ret=1){
	for(; k; k>>=1,x=x*x%mod)
		(k&1)&&(ret=ret*x%mod);
	return ret;
}
void modp(int&x){
	x>=mod&&(x-=mod);
}
void modn(int&x){
	x<0&&(x+=mod);
}
void modma(int&x,const int a,const int b){
	x=(x+ll(a)*b)%mod;
}
constexpr int max_n=1000000;
int f[max_n+2];
void test(){
	int n;
	scanf("%d",&n);
	f[n+1]=0;
	for(int i=n; i>n/2; --i)
		f[i]=(quickpow(iv2,i)+f[i+1])%mod;
	for(int i=n/2; i; --i)
		f[i]=((f[i+1]-f[i*2]+mod)%mod+f[i+1])%mod;
	for(int i=1; i<=n; ++i){
		ll t=quickpow(2,i,f[i]-f[i+1]+mod);
//		printf("%d: %lld\n",i,t);
		if(i!=1&&i!=n)
			t=(t&1)?((t+mod)>>1):(t>>1);
		t=quickpow(iv2,(i-1)-i/2,t);
		printf("%lld\n",t);
	}
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}