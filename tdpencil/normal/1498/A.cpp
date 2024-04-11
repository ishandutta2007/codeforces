#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vt vector
#define pb push_back
// ll m, k, x, y;

// string s;
ll n, m,k;
const int mxN = 3e5+1;
const int M = 1e9+7;
bool nt(ll x) {
	string b=to_string(x);
	ll s=0;
	for(auto &e: b)
		s += (e-'0');

	return __gcd(x, s) <= 1;
}
void solve() {
	cin >> n;

	while(nt(n)) n++;
	cout << n << "\n";
}
int main() {
	// prec();
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; cin >> t;
	for(int case_num = 1; case_num <= t; case_num++) {
		//cout << "Case #" << case_num << ": ";
		solve();
	}
}