#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, i, x, ans; unordered_map<ll,ll> c;
ll f(ll x){return(x)?f(x/2)+(x&1):0;}

int main(){
	for(scanf("%lld",&N),i=0;i<N;i++){
		scanf("%lld",&x); x=f(x);
		ans += c[x]; c[x]++;
	}
	printf("%lld\n",ans);
	return 0;
}