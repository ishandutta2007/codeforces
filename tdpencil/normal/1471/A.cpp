#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn = 2e5;
int a[mxn];
void solve();
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);


	int t; cin >> t;
	while(t--) {
		solve();
	}
}

void solve() {
	int n, m;
	cin >> n >> m;

	ll f = 0, s = 0;

	vector<ll> a(n);
	for(int i=0; i < n; i++) cin >> a[i];

	for(int i=0; i < n; i++) f += (a[i] + m - 1) / m;

	for(int i=0; i < n; i++) s += a[i];

	cout << (s + m - 1) / m << " " << f <<  "\n";
}