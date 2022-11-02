#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

#define lld I64d

long long max(long long a, long long b) {
	if (a < b) {
		return b;
	}
	return a;
}

int main() {
#ifdef ONLINE_JUDGE
	//freopen("painting.in", "r", stdin);
	//freopen("painting.out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	long long sum = 0;
	long long mx = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		mx = max(mx, a);
		sum += a;
	}
	n--;
	if (sum % n == 0) {
		printf("%lld", max(mx, sum / n));
	} else {
		printf("%lld", max(mx, sum / n + 1));
	}
	return 0;
}