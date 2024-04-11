#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, pos, l, r;
	cin >> n >> pos >> l >> r;

	if (l == 1 && r == n) {
		cout << 0 << '\n';
	} else if (l == 1) {
		cout << abs(pos - r) + 1 << '\n';
	} else if (r == n) {
		cout << abs(pos - l) + 1 << '\n';
	} else {
		cout << abs(r - l) + min(abs(pos - l), abs(pos - r)) + 2 << '\n';
	}
}