#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int a, b;
		cin >> a >> b;
		if (b > a && (b - a) % 2 == 0 || b < a && (a - b) % 2 == 1) {
			cout << 2 << '\n';
		} else if (b == a) {
			cout << 0 << '\n';
		} else {
			cout << 1 << '\n';
		}
	}
}