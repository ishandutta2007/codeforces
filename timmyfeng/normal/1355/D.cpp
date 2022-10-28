#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, s;
	cin >> n >> s;
	if (n * 2 <= s) {
		cout << "YES" << '\n';
		for (int i = 0; i < n - 1; ++i) {
			cout << 2 << ' ';
		}
		cout << s - 2 * n + 2 << '\n';
		cout << 1 << '\n';
	} else {
		cout << "NO" << '\n';
	}
}