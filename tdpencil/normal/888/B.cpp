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
	pair<int, int> c(0, 0);
	int n; cin >> n;
	string in;
	cin >> in;
	int mx = 0;
	int cur = 0;
	for(auto &ch: in) {
		if(ch == 'L') c.first--;
		if(ch == 'R') c.first++;
		if(ch == 'U') c.second++;
		if(ch == 'D') c.second--;
		
	}

	cout << n - abs(c.first) - abs(c.second) << "\n";
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; //cin >> t;
	while(t--)
		solve();
}