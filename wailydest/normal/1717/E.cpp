#include <cstdio>
#include <algorithm>

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

const int N = 100005;
int n, phi[N];
bool pr[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i < N; ++i) phi[i] = i;
	for (int i = 2; i < N; ++i) if (!pr[i]) {
		for (int j = i; j < N; j += i) {
			pr[j] = 1;
			phi[j] /= i;
			phi[j] *= i - 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) 
		for (int j = i * 2; j < n; j += i) 
			ans = add(ans, mul(phi[j / i], mul((n - j) / std::__gcd(n - j, i), i)));
	printf("%d\n", ans);
	return 0;
}