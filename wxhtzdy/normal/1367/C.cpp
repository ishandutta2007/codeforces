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
		string s;
		cin >> s;
		int a[n], b[n];
		a[0] = (s[0] == '1' ? 0 : -k-1);
		b[n - 1] = (s[n - 1] == '1' ? n - 1 : n + k);
		for (int i = 1; i < n; i++) {
			if (s[i] == '1') {
				a[i] = i;
			} else {
				a[i] = a[i - 1];
			}
		}
		for (int i = n - 2; i >= 0; i--) {
			if (s[i] == '1') {
				b[i] = i;
			} else {
				b[i] = b[i + 1];
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				a[i] = max(a[i], a[i - 1]);
			}
			if (i - a[i] > k && b[i] - i > k) {
				cnt++;
				a[i] = i;
			}
		}
		cout << cnt << endl;
	}	
	return 0;
}