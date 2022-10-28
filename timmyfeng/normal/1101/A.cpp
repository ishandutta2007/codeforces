#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int l, r, d;
		cin >> l >> r >> d;
		if (d >= l && d <= r) {
			cout << (r / d + 1) * d << '\n';
		} else {
			cout << d << '\n';
		}
	}
}