#include<bits/stdc++.h>
#define ll long long

int T;

inline ll cal(ll x){
	if(!x)
		return 0;
	ll tmp=0;
	ll l=1,r=1e9,res=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(mid*mid<=x)
			res=mid,l=mid+1;
		else
			r=mid-1;
	}
	tmp+=res;
	l=1,r=1e9,res=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(mid*(mid+1)<=x)
			res=mid,l=mid+1;
		else
			r=mid-1;
	}
	tmp+=res;
	l=1,r=1e9,res=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(mid*(mid+2)<=x)
			res=mid,l=mid+1;
		else
			r=mid-1;
	}
	tmp+=res;
	return tmp;
}

int main(){
	scanf("%d",&T);
	while(T--){
		ll l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",cal(r)-cal(l-1));
	}
}