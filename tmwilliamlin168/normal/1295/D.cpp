#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	ll a, m;
	cin >> a >> m;
	ll g=__gcd(a, m);
	m/=g;
	ll m2=m;
	for(ll i=2; i*i<=m2; ++i) {
		if(m2%i)
			continue;
		m=m*(i-1)/i;
		while(m2%i==0)
			m2/=i;
	}
	if(m2>1) {
		m=m/m2*(m2-1);
	}
	cout << m << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}