#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	vector <int> min_a(n);
	min_a[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		min_a[i] = min(a[i], min_a[i + 1]);
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > min_a[i + 1]) {
			ans = i + 1;
		}
	}
	printf("%d", ans);
	return 0;
}