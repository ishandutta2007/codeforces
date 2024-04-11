#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, t;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n % 2 == 1) {
			n -= 3;
			cout << 7;
		}
		while (n) {
			cout << 1;
			n -= 2;
		}
		cout << "\n";
	}
}