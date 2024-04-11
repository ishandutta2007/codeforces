#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const long long MOD = 1000000009ll;

long long pow2(long long n) {
	if (n == 0) return 1;
	if (n == 1) return 2;
	long long w = pow2(n / 2);
	if (n & 1) {
		return w * w % MOD * 2 % MOD;
	} else {
		return w * w % MOD;
	}
}

int main() {
	long long n, m, k;
	cin >> n >> m >> k;
	long long ans;
	if (n - n / k >= m) {
		ans = m;
	} else {
		long long kblock = (m - (n - n / k));
		ans = (pow2(kblock + 1) - 2 + MOD) % MOD * k % MOD + m - kblock * k;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}