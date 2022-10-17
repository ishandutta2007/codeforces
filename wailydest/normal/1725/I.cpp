#include <cstdio>

const int md = 998244353;

inline int mul(int a, int b) {
	return (long long)a * b % md;
}

const int N = 100000;
int n, top[N], size[N];

int find(int a) {
	if (top[a] == -1) return a;
	return top[a] = find(top[a]);
}

int main() {
	scanf("%d", &n);
	int ans = 1;
	for (int i = 0; i < n; ++i) {
		top[i] = -1;
		size[i] = 1;
	}
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		a = find(a);
		b = find(b);
		ans = mul(ans, mul(size[a], size[a]));
		ans = mul(ans, mul(size[b], size[b]));
		top[b] = a;
		size[a] += size[b];
	}
	for (int i = 2 * n - 3; i > 1; i -= 2) ans = mul(ans, i);
	printf("%d\n", ans);
	return 0;
}