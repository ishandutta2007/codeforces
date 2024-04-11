#include<bits/stdc++.h>

using namespace std;

int main () {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		int ans = m / 2 * n;
		if (m % 2) {
			ans += n / 2 + n % 2;
		}
		cout << ans << endl;
	}
}