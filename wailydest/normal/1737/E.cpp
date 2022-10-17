#include <cstdio>

const int md = 1000000007;

inline int add(int a, int b) {
	return a + b < md ? a + b : a + b - md;
}
inline int sub(int a, int b) {
	return a - b < 0 ? a - b + md : a - b;
}
inline int mul(int a, int b) {
	return (long long)a * b % md;
}
int po(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) r = mul(r, a);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}
inline int inv(int a) {
	return po(a, md - 2);
}
inline int di(int a, int b) {
	return mul(a, inv(b));
}

const int N = 1000005;
int t, n, ans[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int s = 0;
		for (int i = n - 1, j = n - 1; i >= 0; --i) {
			for (;j >= i * 2 + 1; --j) s = add(s, ans[j]);
			ans[i] = sub(1, s);
			ans[i] = mul(ans[i], po(md + 1 >> 1, i >> 1));
			if (i != n - 1) ans[i] = mul(ans[i], md + 1 >> 1);
		}
		for (int i = 0; i < n; ++i) printf("%d\n", ans[i]);
	}
	return 0;
}