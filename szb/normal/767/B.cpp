#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,l,r,t,n,m=1e12+7,ans;
ll aabs(ll x){return x>0?x:-x;}
int main(){
	scanf("%lld%lld%lld%lld",&l,&r,&t,&n);
	while(n--){
		scanf("%lld",&a);
		if(a<=r-t&&a){
			//
			if(max(l,a-1)<=r-t&&aabs(l-(a-1))<m)
			//1
				m=aabs(l-(a-1)),ans=min(a-1,l);
			l=max(l,a)+t;//now,
		}
	}
	if(l<=r-t) ans=l;
	//
	printf("%lld\n",ans);
	return 0;
}