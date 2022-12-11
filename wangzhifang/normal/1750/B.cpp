#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int mod=998244353;
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
int a[max_n+1];
void test(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%1d",a+i);
	ll ans=0,x=0,y=0,a=0,b=0;
	for(int i=1; i<=n; ++i){
		if(::a[i]==1)
			++x,++a,b=0;
		else
			++y,++b,a=0;
		if(a*a>ans)
			ans=a*a;
		if(b*b>ans)
			ans=b*b;
	}
	if(x*y>ans)
		ans=x*y;
	printf("%lld\n",ans);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}