#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

const int p = 1000000009;

long long binary_pow(long long a, int n) {
	long long result = 1;
	while (n != 0) {
		if ((n & 1) == 1) {
			result = (result * a) % p;
			n--;
		} else {
			a = (a * a) % p;
			n >>= 1;
		}
	}
	return result; 
}

int main() {
	long long n, m, k;
	scanf("%I64d %I64d %I64d", &n, &m, &k);
	long long result = 0;
	long long count = n / k;
	if (n - count * k <= m) {
		result += n - count * k;
		m -= n - count * k;
	} else {
		result += m;
		m = 0;
	}
	if ((k - 1) * count < m) {
		m -= (k - 1) * count;
		result += (count - m) * (k - 1);
		result += 2 * k * (binary_pow(2, m) - 1);
	} else {
		result += m;
	}
	printf("%d", result % p);
	return 0;
}