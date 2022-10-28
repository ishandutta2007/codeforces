#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ans = 0;
		while (n >= 10) {
			ans += n - n % 10;
			n = n % 10 + n / 10;
		}
		ans += n;
		cout << ans << '\n';
	}
}