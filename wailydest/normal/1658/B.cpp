#include <cstdio>

const int md = 998244353;

inline int mul(int a, int b) {
	return (long long)a * b % md;
}

int t, n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n & 1) printf("0\n");
		else {
			int k = 1;
			for (int i = 1; i <= n / 2; ++i) k = mul(k, i);
			printf("%d\n", mul(k, k));
		}
	}
	return 0;
}