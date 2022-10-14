#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vt vector
const int mxN = 2e5+5;
const int mnN = 1e5+5;
const int grn = 105;
const int grN = 505;
const int griN = 1005;
const int mxGriN= 5005;
const int mxDP = 7005;
ll dp[mxN];
void solve() {
	ll a, b;
	cin >> a >> b;
	if(b < a) swap( a, b);
	if(b%a!=0) {
		cout << -1 << "\n";
		return;
	}
	ll dist = b/a;
	int ans=0;
	while(dist > 1) {
		if(dist&1) {
			cout << -1 << "\n";
			return;
		}
		if(dist % 8 == 0) dist /= 8;
		else if(dist % 4 == 0) dist /= 4;
		else if(dist % 2 == 0) dist /= 2;
		ans++;
	}
	cout << ans << "\n";
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; cin >> t;
	while(t--)
		solve();
}