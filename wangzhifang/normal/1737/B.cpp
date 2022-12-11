#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sqrtll(const ll x){
	if(!x)
		return 0;
	ll ans=sqrt(x);
	while(ans*ans<x)
		++ans;
	while(ans*ans>x)
		--ans;
	return ans;
}
ll f(const ll x){
	if(!x)
		return 2;
	const ll a=sqrtll(x);
	return x/a-a+a*3;
}
void test(){
	ll l,r;
	scanf("%lld%lld",&l,&r);
	const ll ans=f(r)-f(l-1);
	printf("%lld\n",ans);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}