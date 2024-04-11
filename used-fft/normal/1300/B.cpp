#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		int a[2*n]; for(int &i : a) cin >> i;
		sort(a, a + 2*n);
		cout << (a[n] - a[n-1]) << '\n';
	}
}