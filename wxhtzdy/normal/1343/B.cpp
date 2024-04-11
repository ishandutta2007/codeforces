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
		if ((n / 2) % 2 == 1) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		int a[n];
		for (int i = 0; i < n / 2; i++) {
			a[i] = (i + 1) * 2;
		}
		int m = n / 4;
		for (int i = n / 2; i < n / 2 + m; i++) {
			a[i] = a[i - n / 2] - 1;
		} 
		for (int i = n / 2 + m; i < n; i++) {
			a[i] = a[i - n / 2] + 1;
		}
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
	return 0;
}