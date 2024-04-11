#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		int a[n];
		int b[2] = {0, 0};
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[a[i] % 2]++;
		}
		sort(a, a + n);
		int cnt = 0;
		for (int i = 1; i < n; i++) {
			if (a[i - 1] == a[i] - 1) {
				cnt++;
				i++;
			}
		}
		if(cnt > 0 || b[0] % 2 == 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}