#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, d, l;

const int N = 105;
int a[N];

int main() {
	scanf("%d%d%d", &n, &d, &l);
	if (n % 2 == 1) {
		--d;
		a[n - 1] = 1;
	}
	for (int i = 0; i + 1 < n; i += 2) {
		if (d < 0) {
			a[i + 1] = l, a[i] = max(1, l + d);
		} else {
			a[i] = l, a[i + 1] = max(1, l - d);
		}
		d -= a[i] - a[i + 1];
	}
	if (n % 2 == 1) {
		a[n - 1] += d;
		if (a[n - 1] < 1) {
			d = 1 - a[n - 1];
		} else if (a[n - 1] > l) {
			d = a[n - 1] - l;
		} else {
			d = 0;
		}
	}
	if (d != 0) {
		printf("-1\n");
	} else {
		for (int i = 0; i < n; ++i) {
			printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
		}
	}
	return 0;
}