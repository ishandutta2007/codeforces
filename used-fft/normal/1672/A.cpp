#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		int sum {};
		while(n--) {
			int v; cin >> v;
			sum += v - 1;
		}
		cout << (sum & 1 ? "errorgorn" : "maomao90") << '\n';
	}
}