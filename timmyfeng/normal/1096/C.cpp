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
		int ans = -1;
		for (int i = 3; i <= 360; ++i) {
			if (360 % i)
				continue;
			if (n <= 180 - 360 / i && 2 * n % (360 / i) == 0) {
				ans = i;
				break;
			}
		}
		cout << ans << '\n';
	}
}