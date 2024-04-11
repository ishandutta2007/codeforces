#include"bits/stdc++.h"
#define ll long long

int T;

inline bool qry(ll x){
	static int res;
	printf("? %lld\n",x);
	fflush(stdout);
	scanf("%d",&res);
	return res;
}

ll n;

std::vector<ll> a;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		ll l=1,r=n-1;
		a.clear();
		while(l<=r){
			ll mid=(l+r)>>1;
			a.push_back(mid);
			l=mid+1;
		}
		std::reverse(a.begin(),a.end());
		ll pos=n,tp=1;
		for(auto x:a)
			pos+=x*(tp*=-1);
		l=1,r=n-1;
		ll ans=n;
		qry(pos);
		while(l<=r){
			ll mid=(l+r)>>1;
			if(qry(pos+=mid*(tp*=-1))){
				r=mid-1;
				ans=mid;
			}
			else
				l=mid+1;
		}
		printf("= %lld\n",ans);
		fflush(stdout);
	}
}