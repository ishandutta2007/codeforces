#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

const int MAXN = 1010;
bool x[MAXN];
bool y[MAXN];

int main() {
	for (int i = 0; i < MAXN; i++) {
		x[i] = true;
		y[i] = true;
	}
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int cx, cy;
		scanf("%d %d", &cx, &cy);
		x[cx] = false;
		y[cy] = false;
	}
	int res = 0;
	if (n % 2 == 1) {
		if (x[(n + 1) / 2] || y[(n + 1) / 2]) {
			res++;
		}
	}
	for (int i = 2; i <= n / 2; i++) {
		int first, second;
		first = i;
		second = n - i + 1;
		if (x[first] && x[second] && y[first] && y[second]) {
			res += 4;
		} else if (x[first] && y[first] && y[second]) {
			res += 3;
		} else if (x[second] && y[first] && y[second]) {
			res += 3;
		} else if (y[first] && x[first] && x[second]) {
			res += 3;
		} else if (y[second] && x[first] && x[second]) {
			res += 3;
		} else {
			res += min(2, x[first] + x[second] + y[first] + y[second]);
		}
	}
	printf("%d", res);
	return 0;
}