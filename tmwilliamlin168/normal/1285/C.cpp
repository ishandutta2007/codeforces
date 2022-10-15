#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll x;
	cin >> x;
	ll a1, a2;
	for(ll i=1; i*i<=x; ++i) {
		if(x%i)
			continue;
		ll b1=i, b2=x/i;
		if(__gcd(b1, b2)==1)
			a1=b1, a2=b2;
	}
	cout << a1 << " " << a2;
}