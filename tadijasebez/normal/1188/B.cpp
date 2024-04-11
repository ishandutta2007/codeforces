#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n,mod,k;scanf("%i %i %i",&n,&mod,&k);
	auto mul=[&](int x,int y){return (ll)x*y%mod;};
	auto sub=[&](int x,int y){x-=y;return x<0?x+mod:x;};
	map<int,int> cnt;
	ll ans=0;
	while(n--){
		int x;scanf("%i",&x);
		int y=sub(mul(mul(x,x),mul(x,x)),mul(x,k));
		ans+=cnt[y];
		cnt[y]++;
	}
	printf("%lld\n",ans);
	return 0;
}