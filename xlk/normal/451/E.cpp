#include <stdio.h>
#include <iostream>
using namespace std;
int p = 1000000007;
int v[60];
long long C(long long x, int y) {
	long long re = 1;
	for (int i = 0; i < y; i++) {
		re = (x - i) % p * re % p * v[i + 1] % p;
	}
	return re;
}
int n;
long long s, ans;
long long a[30];
int main() {
	scanf("%d %I64d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%I64d", &a[i]);
	}
	v[1] = 1;
	for (int i = 2; i <= 20; i++) {
		v[i] = (long long)v[p % i] * (p - p / i) % p;
	}
	for (int i = 0; i < 1 << n; i++) {
		long long t = s;
		int c = 1;
		for (int j = 0; j < n; j++) {
			if (i >> j & 1) {
				t -= a[j] + 1;
				c = -c;
			}
		}
		if (t >= 0) {
			ans += c * C(t + n - 1, n - 1);
			if (ans < 0) {
				ans += p;
			} else if (ans >= p){
				ans -= p;
			}
		}
	}
	printf("%d\n", (int)ans);
}