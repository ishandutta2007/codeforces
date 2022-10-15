#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll k, d, t;
	cin >> k >> d >> t;
	ll ckd=(k+d-1)/d, a=ckd*d;
	ld cpc=(ld)k/t+(ld)(a-k)/t/2;
	ll cs=1/cpc;
	ld ans=cs*a, cl=1-cs*cpc;
	if(cl<=(ld)k/t)
		ans+=cl*t;
	else {
		ans+=k;
		cl-=(ld)k/t;
		ans+=cl*2*t;
	}
	cout << setprecision(17) << ans;
}