#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	int a[2*n]; for(int &i : a) cin >> i;

	sort(a, a + 2*n);
	if(a[0] != a[2*n-1]) {
		for(int i : a) cout << i << ' ';
	} else cout << -1;
}