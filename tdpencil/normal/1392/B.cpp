#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vt vector
// ll m, k, x, y;

string s;
ll n, m, q;
const int mxN = 2e5+1;
const int M = 1e9+7;
ll a[mxN+1];
ll b[mxN+1];

void solve() {
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	if(m <= 2) {
		while(m--) {
			int p = *max_element(a, a+n);
			for(int i = 0; i < n; i++)
				a[i]=p-a[i];
		}

		for(int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << "\n";
	} else {
		q=2 + m%2;
		while(q--) {
			int p = *max_element(a, a+n);
			for(int i = 0; i < n; i++)
				a[i]=p-a[i];
		}
		for(int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << "\n";

	}
}
int main() {
	// prec();
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; cin >> t;
	for(int case_num = 1; case_num <= t; case_num++) {
		// cout << "Case #" << case_num << ": ";
		solve();
	}
}