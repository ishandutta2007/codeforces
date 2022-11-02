#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		int a[n], b[n];
		for(int &i : a) cin >> i;
		for(int &i : b) cin >> i;
		sort(a, a + n);
		sort(b, b + n);
		for(int i : a) cout << i << ' ';
		cout << '\n';
		for(int i : b) cout << i << ' ';
		cout << '\n';
	}
}