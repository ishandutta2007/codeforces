#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int prev = n / k * k;
		if (n - prev <= k / 2) {
			cout << n << '\n';
		} else {
			cout << prev + k / 2 << '\n';
		}
	}
}