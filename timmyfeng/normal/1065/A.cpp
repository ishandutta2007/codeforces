#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll s, a, b, c;
		cin >> s >> a >> b >> c;
		ll cnt = s / c;
		cout << cnt + cnt / a * b << '\n';
	}
}