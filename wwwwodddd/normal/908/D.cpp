#include <bits/stdc++.h>
using namespace std;
int p = 1000000007;
long long pw(long long x, int y) {
	long long re = 1;
	for (; y > 0; y >>= 1) {
		if (y & 1) {
			re = re * x % p;
		}
		x = x * x % p;
	}
	return re;
}

long long f[1020][1020]; // f[i][j] i ge a, j ge ab
int main() {
	int k, pa, pb;
	scanf("%d%d%d", &k, &pa, &pb);
	long long ab = pw(pa + pb, p - 2);
	f[1][0] = 1;
	long long ans = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= k; j++) {
			if (j + i >= k) {
				ans = (ans + (j + i + pa * pw(pb, p - 2) % p) * f[i][j]) % p;
			} else {
				f[i + 1][j] = (f[i + 1][j] + f[i][j] * pa % p * ab % p) % p;
				f[i][j + i] = (f[i][j + i] + f[i][j] * pb % p * ab % p) % p;
			}
		}
	}
	printf("%d\n", (int)ans);
	return 0;
}