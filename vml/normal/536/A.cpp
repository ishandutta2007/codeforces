#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <cassert>

using namespace std;

const int maxn = (int)3e6 + 10;

long long v[maxn];
long long sum[maxn];
int a, b;

bool go(int l, int r, int t, int m) {
	if (r - l + 1 <= m) {
		return v[r] <= t;
	}

	return (long long)m * t >= sum[r] - sum[l - 1] && t >= v[r];
}

int main() {
	int n;

	scanf("%d %d %d", &a, &b, &n);

	for (int i = 1; i < maxn; i++) {
		v[i] = a + (long long)b * (i - 1);
		sum[i] = v[i] + sum[i - 1];
	}

	for (int i = 0; i < n; i++) {
		int l, m, t;

		scanf("%d %d %d", &l, &t, &m);

		int left = l;
		int right = maxn - 1;

		while (left != right) {
			int mid = (left + right + 1) / 2;

			if (go(l, mid, t, m)) {
				left = mid;
			} else {
				right = mid - 1;
			}
		}

		if (go(l, left, t, m)) {
			printf("%d\n", left);
		} else {
			printf("-1\n");
		}
	}

	return 0;
}