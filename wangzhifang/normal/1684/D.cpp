#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int mod=998244353;
template<int mod=::mod>ll quickpow(ll x,int k,ll ret=1){
	for(; k; k>>=1,x=x*x%mod)
		(k&1)&&(ret=ret*x%mod);
	return ret;
}
constexpr int max_n=200000;
int a[max_n+1];
void test(){
	int n,k;
	scanf("%d%d",&n,&k);
	ll sum=0;
	for(int i=1; i<=n; ++i){
		scanf("%d",a+i);
		sum+=a[i];
		a[i]-=n-i;
	}
	sum-=k*ll(k-1)/2;
	k=n-k+1;
	nth_element(a+1,a+k,a+n+1);
	for(int i=k; i<=n; ++i)
		sum-=a[i];
	printf("%lld\n",sum);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}