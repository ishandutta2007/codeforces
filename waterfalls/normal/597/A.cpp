#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll a, ll k) {
	if (a<0) return 0;
	return a/k+1;
}

ll k,a,b;

int main() {
	scanf("%lld%lld%lld",&k,&a,&b);
	ll ans = 0;
    if (a<=0 && b<=0) a*=-1, b*=-1, swap(a,b);
    if ((a<0)+(b<0)==1) ans = solve(abs(a),k)+solve(abs(b),k)-1;
    else ans = solve(b,k)-solve(a-1,k);
    printf("%lld\n",ans);

	return 0;
}