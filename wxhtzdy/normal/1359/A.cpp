#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m, k;
		cin >> n >> m >> k;
		int a = n / k;
		if (m <= a) {
			cout << m << endl;
			continue;
		} else {
			m -= a;
			int ans = m / (k - 1);
			if(m % (k - 1) > 0) {
				ans++;
			}
			cout << a - ans << endl;
		}
	}
	return 0;	
}