#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;
ll qpow(ll b,ll exp){
	if(!exp) return 1LL;
	else if(exp&1) return (b*qpow(b,exp-1))%mod;
	else{ll r=qpow(b,exp>>1); return (r*r)%mod;}
}
ll n, k, ans;
int main(){
	scanf("%lld%lld",&n,&k);
	if(!n){printf("0\n");return 0;}
	n %= mod; ans=qpow(2,k+1)*n%mod;
	if(k) ans=(ans-qpow(2,k)+1+mod)%mod;
	printf("%lld\n",ans);
	return 0;
}