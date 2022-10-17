#include <stdio.h>
#include <iostream>
using namespace std;
int p = 1000000007;
int n, x, N = 20, ans;
long long c[1100000];
long long b[1100000];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		c[x]++;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 1 << N; j++) {
			if (j >> i & 1) {
				c[j ^ (1 << i)] += c[j];
			}
		}
	}
	b[0] = 1;
	for (int i = 1; i <= 1 << N; i++) {
		b[i] = b[i - 1] * 2 % p;
	}
	for (int i = 0; i < 1 << N; i++) {
		if (__builtin_popcount(i) & 1) {
			ans += p - b[c[i]];
		} else {
			ans += b[c[i]];
		}
		if (ans >= p) {
			ans -= p;
		}
	}
	printf("%d\n", (int)ans);
}