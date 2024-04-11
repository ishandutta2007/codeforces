#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)

using namespace std;

int t, n, x;

void solve() {
	cin >> n >> x;
	vector<int> a(n), b(n), c(n);
	rep(i, 0, n - 1)
		cin >> a[i];
	int s = 0;
	rep(i, 1, n) {
		int y = -1;
		rep(j, 0, n - 1)
			if (!b[j] && s + a[j] != x) 
				y = j;
		if (y == -1) {
			cout << "NO\n";
			return;
		}
		s += a[y];
		c[i - 1] = a[y];
		b[y] = 1;
	}
	cout << "YES\n";
	rep(i, 0, n - 1)
		cout << c[i] << " ";
	cout << endl;
}

int main() {
	cin >> t;
	while (t--) 
		solve();
	
	return 0;
}