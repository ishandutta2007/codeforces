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
ll f(int a,const int m){
	vector<int>p;
	for(int i=2; i*i<=a; ++i)
		if(!(a%i)){
			p.emplace_back(i),a/=i;
			while(!(a%i))
				a/=i;
		}
	if(a>1)
		p.emplace_back(a);
	ll ans=0;
	for(int i=1<<p.size(); --i>=0; ){
		int x=m,t=i;
		for(int j=0; t; ++j)
			if((t&(1<<j)))
				x/=-p[j],t^=1<<j;
		ans+=x;
	}
	return ans;
}
void test(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	ll ans=1;
	for(int i=2; i<=n; ++i){
		if((a[i-1]%a[i])){
			puts("0");
			return;
		}
		if(a[i]==a[i-1]){
			ans=ans*(m/a[i])%mod;
			continue;
		}
		ans=ans*f(a[i-1]/a[i],m/a[i])%mod;
	}
	printf("%lld\n",ans);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}