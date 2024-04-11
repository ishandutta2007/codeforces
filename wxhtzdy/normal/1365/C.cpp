#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int n;
	cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int pos[n + 1];
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		pos[b[i]] = i;
	}
	int right[n + 1];
	for (int i = 0; i <= n; i++) {
		right[i] = 0;
	}
	int left[n + 1];
	for (int i = 0; i <= n; i++) {
		left[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		int x = pos[a[i]] - i;
		if (x > 0) {
			right[x]++;
			left[n - x]++;
		} else {
			x = abs(x);
			left[x]++;
			right[n - x]++;
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		ans = max(ans, right[i]);
		ans = max(ans, left[i]);
	}
	cout << ans << endl;
 	return 0;
}