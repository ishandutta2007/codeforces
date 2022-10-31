#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<ll> basis;

bool add(ll x) {
	for (ll i: basis) {
		if (x&i&-i) x^=i;
	}
	if (!x) return false;
	for (ll& i: basis) {
		if (i&x&-x) i^=x;
	}
	basis.push_back(x);
	return true;
}

int main() {
	scanf("%d",&n);
	ll tot = 0;
	for (int i=0;i<n;i++) {
		ll a,b;
		scanf("%lld%lld",&a,&b);
		tot^=a;
		add(a^b);
	}
	if (add(tot)) printf("1/1\n");
	else printf("%lld/%lld\n",(1LL<<basis.size())-1,(1LL<<basis.size()));

	return 0;
}