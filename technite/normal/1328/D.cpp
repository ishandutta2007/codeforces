#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		int pre = -1, u;
		cin >> n >> u;
		int a[n], k = 1, r = -1;
		a[0] = 1;
		pre = u;
		for (int i = 1; i < n; ++i) {
			int j;
			cin >> j;
			if (j == pre) a[i] = a[i - 1], r = i;
			else a[i] = 3 - a[i - 1], k = 2;
			pre = j;
		}
		if (u != pre && a[0] == a[n - 1]) {
			if (r > 0) {
				for (int i = r; i < n; ++i) a[i] = 3 - a[i];
			}
			else a[n - 1] = 3, k = 3;
		}
		cout << k <<endl;
		for (int i : a) cout << i <<" ";
		cout <<endl;
	}
}