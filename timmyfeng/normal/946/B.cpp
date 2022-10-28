#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll a, b;
	cin >> a >> b;
	
	while (a && b) {
		if (a >= 2 * b) {
			a %= 2 * b;
		} else if (b >= 2 * a) {
			b %= 2 * a;	
		} else {
			break;
		}
	}

	cout << a << ' ' << b << '\n';
}