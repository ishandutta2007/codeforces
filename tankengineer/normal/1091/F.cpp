#include<cassert>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005, D = 2;

int n;

long long l[N];

char s[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%I64d", l + i);
		l[i] *= D;
	}
	scanf("%s", s);
	long long x = 0, y = 0, z = 0, xy = 0, xz = 0;
	bool haswater = false;
	if (s[0] == 'G') {
		z = xz = x = l[0] / 2;
	} else {
		y = xy = x = l[0] / 2;
		haswater = true;
	}
	for (int i = 1; i < n; ++i) {
		if (s[i] == 'L') {
			long long left = l[i];

			long long delta1 = min(left / 2, xy);
			x += delta1;
			y += delta1;
			xy -= delta1;
			left -= delta1 * 2;

			long long delta2 = min(left / 2, xz);
			x += delta2;
			z += delta2;
			xz -= delta2;
			left -= delta2 * 2;

			if (haswater) {
				x += left;
				y += left;
			} else {
				x += left;
				z += left;
			}

		} else if (s[i] == 'G') {
			long long left = l[i];

			long long delta1 = min(left / 2, xy);
			x += delta1;
			y += delta1;
			xy -= delta1;
			xz += delta1 * 2;
			left -= delta1 * 2;

			x += left / 2;
			z += left / 2;
			xz += left / 2;
		} else if (s[i] == 'W') {
			long long delta = l[i] / 2;
			x += delta;
			y += delta;
			xy += delta;
			haswater = true;
		}
	}
	long long ans = (x + 3 * y + 5 * z) / D;
	printf("%I64d\n", ans);
	assert((x + 3 * y + 5 * z) % D == 0);
	return 0;
}