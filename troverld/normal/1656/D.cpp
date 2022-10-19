#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll n;
ll mina(){
	scanf("%lld",&n);
	ll _n=n;
	for(ll i=2;;i<<=1){
		ll s=i*(i+1)>>1;
		if(s>n)break;
		if((n-s)%i==0)return i;
	}
	while(!(_n&1))_n>>=1;
	for(int i=1;1ll*i*i<=_n;i+=2)if(!(_n%i)){
		if(i!=1&&(1ll*i*(i+1)>>1)<=n)return i;
		ll _i=_n/i;
		if(_i!=1&&_i<=2e9&&(1ll*_i*(_i+1)>>1)<=n)return _i;
	}
	return -1;
}
int main(){
	scanf("%d",&T);
	while(T--)printf("%lld\n",mina());
	return 0;
}
/*
1
18984100119445504
*/