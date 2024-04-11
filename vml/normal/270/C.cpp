#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector <int> a(n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a, k;
		scanf("%d %d", &k, &a);
		if (a == 1) {
			ans = max(ans, k + 1);
		} else {
			ans = max(ans, (int)(ceil((2 * k + log(a * 1.0) / log(2.0)) / 2)));
		}
	}
	printf("%d", ans);
	return 0;
}