#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> vec; ll ans;
void gen(ll n,ll tot){
	if(n==0) vec.push_back(tot);
	else{
		gen(n-1, tot*10+4LL);
		gen(n-1, tot*10+7LL);
	}
}

int main(){
	ll l, r; scanf("%lld%lld",&l,&r);
	for(int i=10;i>=1;i--) gen(i,0);
	vec.push_back(0);
	sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++){
		if(vec[i]>=r){
			ans += vec[i]*(r-max(l-1,vec[i-1]));
			break;
		}
		if(vec[i]>=l) ans += vec[i]*(vec[i]-max(l-1,vec[i-1]));
	}
	printf("%lld\n",ans);
	return 0;
}