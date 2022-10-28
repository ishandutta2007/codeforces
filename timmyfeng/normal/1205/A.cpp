#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	if (n % 2) {
		cout << "YES\n";
		for (int i = 1; i <= n; ++i) {
			cout << i * 2 - i % 2 << " ";
		}
		for (int i = 1; i <= n; ++i) {
			cout << i * 2 - 1 + i % 2 << " ";
		}
		cout << "\n";
	} else {
		cout << "NO\n";
	}
}