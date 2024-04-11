#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int i = n - 2;
		while (k - ((n - 1) - i) > 0) {
			k -= (n - 1 - i);
			--i;
		}
		string ans(n, 'a');
		ans[i] = 'b';
		ans[n - k] = 'b';
		cout << ans << '\n';
	}
}