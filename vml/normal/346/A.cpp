#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main() {
	int n;
	scanf("%d", &n);
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());
	int ans = a[0];
	for (int i = 1; i < n; i++) {
		ans = gcd(ans, a[i]);
	}
	int count = a[n - 1] / ans - n;
	if (count & 1) {
		printf("Alice");
	} else {
		printf("Bob");
	}
	return 0;
}