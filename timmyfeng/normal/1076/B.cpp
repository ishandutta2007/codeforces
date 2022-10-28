#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	for (ll i = 2; i * i <= n; ++i) {
		if (n % i)
			continue;
		cout << 1 + (n - i) / 2 << '\n';
		return 0;
	}
	cout << 1 << '\n';
}