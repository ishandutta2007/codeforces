#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll phi(ll n){
	ll ans=n;
	for(ll i=2;i*i<=n;i++){
		if (n%i==0){
			while(n%i==0)
				n/=i;
			ans-=ans/i;
		}
	}
	if (n!=1)
		ans-=ans/n;
	return ans;
}
int main(){
	ll n,k;
	scanf("%lld%lld",&n,&k);
	k=(k+1)/2;
	while(k--){
		n=phi(n);
		if (n==1)
			break;
	}
	printf("%lld",n%1000000007);
}