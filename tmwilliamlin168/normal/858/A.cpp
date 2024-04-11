#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;

	cin >> n >> k;

	int m = 1;

	for (int i = 0; i < k; i++)
		m *= 10;

	int d = __gcd(n, m);

	long long ans = 1ll * n * m / d;

	cout << ans << endl;


	return 0;
}