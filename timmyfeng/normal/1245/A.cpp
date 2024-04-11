#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << (__gcd(a, b) == 1 ? "Finite" : "Infinite") << '\n';
	}
}