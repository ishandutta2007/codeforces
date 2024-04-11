#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const long long MOD = 1000000009;

long long c[5005][5005];

long long getc(long long m, long long n) {
	//cout << m << ' ' << n << endl;
  if (m == n || m == 0) return 1;
  if (c[n][m] != 0) return c[n][m];
  return c[n][m] = (getc(m, n - 1) + getc(m - 1, n - 1)) % MOD;
}

int main() {
	memset(c, 0, sizeof(c));
	long long b, w, n;
	cin >> n >> w >> b;
	long long ans = 1;
	for (int i = 1; i <= w; ++i) {
	  ans *= i;
	  ans %= MOD;
	}
	for (int i = 1; i <= b; ++i) {
	  ans *= i;
	  ans %= MOD;
	}
	ans *= (w - 1);
	ans %= MOD;
	long long sum = 0;
	for (int i = 1; i <= b; ++i) {
	  if ((n - i) < 2 || (n - i) > w) continue;
	  sum = sum + getc(i - 1, b - 1) * getc(n - i - 2, w - 2);
	  sum = sum % MOD;
	}
	ans = ans * sum % MOD;
	cout << ans << endl;
	return 0;
}