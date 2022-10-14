#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll recalc(ll a, ll b, ll c, ll d) {
	return abs(a-c) + abs(b-d);
}
int main() {
	ll T;
	cin >> T;
	while(T--) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		ll ans = max(recalc(1, 1, c, d), max(recalc(1, b, c, d), max(recalc(a, 1, c, d), recalc(a, b, c, d))));
		cout << ans << '\n';
		
	}
}