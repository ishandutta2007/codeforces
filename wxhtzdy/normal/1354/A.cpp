#include<bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		if(b < a && c <= d) {
			cout << -1 << endl;
			continue;
		}
		a -= b;
		if(a <= 0) {
			cout << b << endl;
			continue;
		}
		int ans = a / (c - d);
		if(a % (c - d) != 0) {
			ans++;
		}
		cout << ans * c + b << endl;
	}
}