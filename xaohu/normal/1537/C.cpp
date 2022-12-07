#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
using namespace std;

int T, n, a[200111];

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		sort(a + 1, a + n + 1);
		int dif = 1e9;
		rep(i, 2, n) dif = min(dif, a[i] - a[i - 1]);
		rep(i, 2, n) {
			if (a[i] - a[i - 1] == dif) {
				cout << a[i - 1] << " ";
				rep(j, i + 1, n) cout << a[j] << " ";
				rep(j, 1, i - 2) cout << a[j] << " ";
				cout << a[i] << endl;
				break;
			}
		}
	}
	return 0;
}