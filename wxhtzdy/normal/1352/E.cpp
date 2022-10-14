#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int left = 0, right = 0;
			int x = a[i];
			int sum = 0;
			bool ok = false;
			while (right < n) {
				if (sum + a[right] <= x) {
					sum += a[right];
					right++;
				} else {
					if (left == right) {
						left++;
						right++;
						continue;
					}
					sum -= a[left];
					left++;
					right = max(right, left);
				}
				if (sum == x && left != right - 1) {
					ok = true;
					break;
				}
			}
			ans += ok;
		}
		cout << ans << endl;
	}
}