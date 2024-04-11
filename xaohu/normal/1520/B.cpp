#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)

using namespace std;

int t, n;

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		int ans = 0;
		rep(i, 1, 9) {
			long long x = i;
			while (x <= n) {
				ans++;
				x = 10 * x + i;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}