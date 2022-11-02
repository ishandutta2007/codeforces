#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <cmath>
using namespace std;

int n, m, a[20], b[20], c[20], d[20], global, ans1[20], ans2[20];

int shareone(int a, int b, int c, int d) {
	int x[2], y[2];
	x[0] = a; x[1] = b;
	y[0] = c; y[1] = d;
	for (int i = 0; i <= 1; i++)
		for (int j = 0; j <= 1; j++)
			if (x[i] == y[j] && x[1 - i] != y[1 - j])
				return x[i];
	return 0;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i], &b[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &c[i], &d[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int k = shareone(a[i], b[i], c[j], d[j]);
			if (!k)
				continue;
			ans1[i] |= (1 << k);
			ans2[j] |= (1 << k);
			global |= (1 << k);
		}
	}
	for (int i = 1; i <= 9; i++)
		if (global == (1 << i)) {
			printf("%d\n", i);
			return 0;
		}
	bool ok = true;
	for (int i = 1; i <= n; i++) {
		bool fi = (ans1[i] == 0);
		for (int j = 1; j <= 9; j++)
			if (ans1[i] == (1 << j))
				fi = true;
		ok &= fi;
	}
	for (int i = 1; i <= m; i++) {
		bool fi = (ans2[i] == 0);
		for (int j = 1; j <= 9; j++)
			if (ans2[i] == (1 << j))
				fi = true;
		ok &= fi;
	}
	if (ok)
		printf("0\n");
	else
		printf("-1\n");
}