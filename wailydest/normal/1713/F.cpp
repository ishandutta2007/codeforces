#include <cstdio>
#include <algorithm>
#include <vector>

const int N = 500000;
int n;

void t(std::vector<int> &vec, int p) {
	vec.resize(1 << p);
	for (int j = 0; j < p; ++j) for (int i = 0; i < 1 << p; ++i) if (i >> j & 1) vec[i] ^= vec[i & ~(1 << j)];
	std::reverse(vec.begin(), vec.end());
}

void f(std::vector<int> &b, int n) {
	if (n == 1) return;
	int p = 31 - __builtin_clz(n - 1);
	std::vector<int> vec(n - (1 << p));
	for (int i = 0; i < n - (1 << p); ++i) vec[i] = b[i] ^ b[(1 << p) + i];
	f(vec, n - (1 << p));
	for (int i = 1 << p; i < n; ++i) b[i] = vec[i - (1 << p)];
	t(vec, p);
	for (int i = 0; i < 1 << p; ++i) b[i] ^= vec[i];
	f(b, 1 << p);
}

int main() {
	scanf("%d", &n);
	std::vector<int> b(n);
	for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
	f(b, n);
	for (int i = n - 1; i >= 0; --i) printf("%d ", b[i]);
	printf("\n");
	return 0;
}