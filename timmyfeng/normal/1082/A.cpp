#include <bits/stdc++.h> 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n,x,y,d;
		cin >> n >> x >> y >> d;
		int ans = 1e9;
		if (x % d == y % d) {
			ans = min(ans, abs(x - y) / d);
		}
		if (1 % d == y % d) {
			ans = min(ans, (x - 2) / d + 1 + (y - 1) / d);
		}
		if (n % d == y % d) {
			ans = min(ans, (x == n ? 0 : (n - x - 1) / d + 1) + (n - y) / d);
		}
		cout << (ans == 1e9 ? -1 : ans) << '\n';
	}
}