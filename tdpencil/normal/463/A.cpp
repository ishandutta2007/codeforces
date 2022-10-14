
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define ar array

const int mxN = 1e5 + 5;


random_device rd;
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int t; cin >> t;
	int s; cin >> s;
	int ans = -1;
	while(t--) {
		int x, y;
		cin >> x >> y;

		int leftOver = 100 - y;
		if(100 * s < 100 * x + y) {
			continue;
		}
		ans = max(ans, (leftOver)%100);
	}	


	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	// cin >> t;
	int i = 1;
	while(t--) {
		solve();
		++i;
	}
}