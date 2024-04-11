#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int test_case;
void solve_componenent() {
	ll n;
	scanf("%lld", &n);

	// lowerbound for this is around 40?
	// 2^x
	// precalculate factorials up to 1e12?
	// if some subset of numbers involves the factorial we can reduce it
	vector<ll> fac(17);
	ll curfac=1;
	int ans=40;
	for(ll i = 1; i < 17; i++) {
		curfac*=i;
		fac[i]=curfac;
	}

	for(int i=0;i<(1<<17);i++) {
		int c=0;
		ll x=n;
		for(int j=1;j<17;j++) {
			if(((1LL<<j)&i)) {
				x-=fac[j];
				c++;
			}
		}
		if(x>=0)
			c+=__builtin_popcountll(x),ans=min(ans,c);
	}
	printf("%d\n", ans);
	
}
int main() {
	scanf("%d", &test_case);

	while(test_case--) {
		solve_componenent();
	}
}