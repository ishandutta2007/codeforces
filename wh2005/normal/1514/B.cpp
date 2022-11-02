#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod = 1e9+7;
int T,n,k;
ll qpow(ll x,ll y){
	ll t=1;while(y){if(y&1) (t*=x)%=mod;(x*=x)%=mod,y>>=1;}
	return t;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		printf("%lld\n",qpow(n,k));
	}
	return 0;
}