#include <bits/stdc++.h>
using namespace std;

const int P = 998244353, MaxN = 200005;

int n, K, sum, Ans;
int jc[MaxN], ny[MaxN], a[MaxN];

int Pow(int a, int b) {
	int ans = 1;
	for (; b; b >>= 1) {
		if (b & 1) ans = 1ll * ans * a % P;
		a = 1ll * a * a % P;
	}
	return ans;
}

int C(int n, int m) {
	if (n < 0 || m < 0 || m > n) return 0;
	return 1ll * jc[n] * ny[m] % P * ny[n - m] % P;
}

int main() {

	jc[0] = ny[0] = 1;
	for (int i = 1; i <= 200000; ++ i) jc[i] = 1ll * jc[i - 1] * i % P;
	ny[200000] = Pow(jc[200000], P - 2);
	for (int i = 199999; i; -- i) ny[i] = 1ll * (i + 1) * ny[i + 1] % P;

	scanf("%d%d", &n, &K);
	for (int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
	
	Ans = 1;
	for (int i = 1; i <= n; ++ i) {
		int nxt = i % n + 1;
		if (a[i] != a[nxt]) ++ sum;
		else Ans = 1ll * Ans * K % P;
	}
	
	int ans = 0;
	for (int i = 0; i < sum; ++ i) {
		int base = 1ll * C(sum, i) * Pow(K - 2, i) % P;
		int total = Pow(2, (sum - i));
		if ((sum - i) % 2 == 0) {
			total = (total + P - C(sum - i, (sum - i) / 2)) % P;
		}
		total = 1ll * total * ((P + 1) / 2) % P;
		ans = (ans + 1ll * total * base) % P;
	}
	Ans = 1ll * Ans * ans % P;
	printf("%d\n", Ans);
	return 0;
}