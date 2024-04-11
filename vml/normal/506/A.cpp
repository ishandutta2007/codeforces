#pragma comment (linker, "/STACK:1000000000")

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

const int maxn = 30010;

int v[maxn];

int m[maxn][2010];
int d;

int go(int pos, int d1) {
	if (d + d1 <= 0) {
		return -100000000;
	}
	if (pos >= maxn) {
		return 0;
	}

	int d2 = d + d1;
	int dd = d1 + 1000;

	if (m[pos][dd] == -1) {
		m[pos][dd] = v[pos] + max(max(go(pos + d2 - 1, d1 - 1), go(pos + d2, d1)), go(pos + d2 + 1, d1 + 1));
	}

	return m[pos][dd];
}

int main() {
	memset(m, 255, sizeof m);
	int n;

	scanf("%d %d", &n, &d);

	for (int i = 0; i < n; i++) {
		int x;

		scanf("%d", &x);

		v[x]++;
	}

	cout << go(d, 0) << endl;

	return 0;
}