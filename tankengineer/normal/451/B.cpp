#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	if (n == 1) {
		puts("yes");
		printf("1 1\n");
		return 0;
	}
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int l = 0;
	while (l + 1 < n && a[l] < a[l + 1]) {
		++l;
	}
	int r = l + 1;
	while (r < n && a[r] < a[r - 1]) {
		++r;
	}
	reverse(a.begin() + l, a.begin() + r);
	for (int i = 1; i < n; ++i) {
		if (a[i] < a[i - 1]) {
			puts("no");
			return 0;
		}
	}
	puts("yes");
	printf("%d %d\n", l + 1, r);
	return 0;
}