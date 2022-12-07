#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; 
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		cout << (1ll << ((int)log2(n)) == n ? "NO\n" : "YES\n");
	}
	return 0;
}