#include <bits/stdc++.h>
using namespace std;

long long n, k, a, b, x, y;

void proc(long long d) {
	d = (d + n * k) % (n * k);
	long long res = n * k / __gcd(n * k, d);
	x = min(x, res);
	y = max(y, res);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> a >> b;
	x = 1e18;

	for (int i = 0; i < n; ++i) {
		proc(i * k - a - b);
		proc(i * k - a + b);
		proc(i * k + a - b);
		proc(i * k + a + b);
	}
	cout << x << " " << y << "\n";
}