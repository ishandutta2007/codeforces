#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

long long modPow(long long b, long long e) {
	if (!e) return 1;
	if (e % 2) return b * modPow(b, e - 1) % MOD;
	long long tmp = modPow(b, e / 2);
	return tmp * tmp % MOD;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long n, m;
	cin >> n >> m;
	cout << modPow(modPow(2, m) - 1, n) << '\n';
}