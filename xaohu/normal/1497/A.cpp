#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
using namespace std;	

int t, n, a[123];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> t;
	while (t--) {
		cin >> n;
		rep(i, 0, n - 1)
			cin >> a[i];
		rep(i, 0, n - 1) {
			int p = find(a, a + n, i) - a;
			if (i < p && p < n)
				rotate(a + i, a + p, a + p + 1);
			cout << a[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}