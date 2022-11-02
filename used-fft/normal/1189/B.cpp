#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	int a[n]; for(int &i : a) cin >> i;

	sort(a, a + n);
	if(a[n-1] >= a[n-2] + a[n-3]) {
		cout << "NO";
	} else {
		cout << "YES\n";
		swap(a[n-1], a[n-2]);
		for(int i : a) cout << i << ' ';
	}
}