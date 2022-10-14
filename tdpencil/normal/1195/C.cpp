#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn = 2e5;
void solve();
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	// int t; cin >> t; while(t--) solve();
	solve();

}

void solve() {
	int n;
	cin >> n;
	vector<array<ll, 2>> v(n);
	for(int i=0;i<n;i++)
		cin >> v[i][0];
	for(int i=0; i < n; i++)
		cin >> v[i][1];

	vector<ll> dp1(n);
	dp1[0] = v[0][0];
	vector<ll> dp2(n);
	dp2[0] = v[0][1];

	for(int i=1; i < n; i++) {
		if(i >= 2) {
			dp1[i] = max(dp2[i-1] + v[i][0], dp2[i-2] + v[i][0]);
			dp2[i] = max(dp1[i-1] + v[i][1], dp1[i-2] + v[i][1]);
		} else {
			dp1[i] = max(dp2[i-1] + v[i][0], dp1[i]);
			dp2[i] = max(dp1[i-1] + v[i][1], dp2[i]);
		}
	}

	cout << max(dp1[n-1], dp2[n-1]); 
}