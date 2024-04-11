#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		int per = n / k;
		if (m <= per) {
			cout << m << '\n';
		} else {
			cout << per - ((m - per - 1) / (k - 1) + 1) << '\n';
		}
	}
}