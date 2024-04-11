#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		if (n < 2) {
			cout << -1 << endl;
			continue;
		}
		for (int i = 0; i < n - 1; i++) {
			cout << 7;
		}
		cout << 8 << endl;
	}
	return 0;
}