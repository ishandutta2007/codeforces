#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a,b,c,n;
		cin >> a >> b >> c >> n;
		int res = (a + b + c + n) / 3;
		cout << ((a + b + c + n) % 3 == 0 && max({a, b, c}) <= res ? "YES" : "NO") << '\n';
	}
}