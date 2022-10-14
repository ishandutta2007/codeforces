#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i > 0) {
				sum += a[i];
			}
		}
		cout << min(k, a[0] + sum) << endl;
	}
	return 0;
}