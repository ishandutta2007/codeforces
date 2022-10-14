#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int mxN=2e5;

void solve() {
	ll x, y;
	cin >> x >> y;
	if(abs(x-y)==1) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t=1;
	cin >> t;
	while(t--) {
		solve();
	}
}