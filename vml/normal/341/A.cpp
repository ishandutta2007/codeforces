#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
	while (b != 0) {
		long long t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main() {
	int n;
	scanf("%d", &n);
	vector <int> a(n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sort(a.begin(), a.end());
	long long s = 0;
	long long cur = 0;
	for (int i = 1; i < n; i++) {
		cur += (long long)(a[i] - a[i - 1]) * i;
		s += cur;
	}
	long long _gcd = gcd(sum + 2 * s, n);
	printf("%I64d %I64d", (sum + 2 * s) / _gcd, (long long)n / _gcd);
	return 0;
}