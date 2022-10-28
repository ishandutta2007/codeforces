#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		if (x == 1 || x == 2 || x == 4 || x == 5 || x == 8 || x == 11) {
			cout << "NO" << '\n';
		} else {
			cout << "YES" << '\n';
		}
	}
}