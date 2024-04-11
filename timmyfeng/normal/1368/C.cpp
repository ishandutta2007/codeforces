#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	cout << 3 * n + 4 << "\n";
	for (int i = 0; i <= 1; ++i) {
		for (int j = 0; j <= 1; ++j) {
			cout << i << " " << j << "\n";
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << i << " " << i + 1 << "\n";
		cout << i + 1 << " " << i << "\n";
		cout << i + 1 << " " << i + 1 << "\n";
	}
}