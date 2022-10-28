#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		long long k;
		int x;
		cin >> k >> x;
		cout << x + (k - 1) * 9 << '\n';
	}
}