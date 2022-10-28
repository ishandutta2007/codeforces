#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string x;
		cin >> n >> x;
		string a(n, '0'), b(n, '0');
		bool greater = false;
		for (int i = 0; i < n; ++i) {
			if (x[i] == '1') {
				if (greater) {
					b[i] = '1';
				} else {
					a[i] = '1';
					greater = true;
				}
			} else if (x[i] == '2') {
				if (greater) {
					b[i] = '2';
				} else {
					b[i] = a[i] = '1';
				}
			}
		}
		cout << a << '\n';
		cout << b << '\n';
	}
}