#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int ans = 1;
	for (int len = 2; len <= n; len *= 2) {
		bool ok = 1;
		int nxt = len - 1;
		for (int i = 0; i < n; i++) {
			if (i == nxt) {
				if (ok) ans = len;
				ok = 1;
				nxt += len;
			}
			if (i != n && a[i] > a[i + 1]) ok = 0;
		}
	}
	cout << ans << endl;
	return 0;
}