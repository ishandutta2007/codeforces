#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;

int t, n, a[55];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n;
		rep(i, 0, 2 * n - 1)
			cin >> a[i];
		sort(a, a + 2 * n);
		rep(i, 0, n - 1) {
			cout << a[i] << " " << a[2 * n - i - 1] << " ";
		}
		cout << "\n";
	}
	return 0;
}