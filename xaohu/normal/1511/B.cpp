#include <bits/stdc++.h>
#define FOR(i, a) for (int i = 0; i < a; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int len(int x) {
	int res = 0;
	while (x) {
		res++;
		x /= 10;
	}
	return res;
}

int t, a, b, c;

int main() {
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		if (c > min(a, b)) {
			cout << "-1\n";
			continue;
		}
		long long gcd = 1;
		while (len(gcd) < c)
			gcd *= 2;
		long long x = gcd;
		while (len(x) < a)
			x *= 3;
		long long y = gcd;
		while (len(y) < b)
			y *= 5;
		cout << x << " " << y << "\n";
	}
	
	return 0;
}