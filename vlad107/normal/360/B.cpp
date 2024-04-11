#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define INF 1000000000
#define N 500500

using namespace std;

int f[N], n, k, l, r, mid, a[N];

bool ok(int c) {
	for (int i = 0; i < n; i++) {
		f[i] = i;
		for (int j = 0; j < i; j++)
			if (abs(a[i] - a[j]) <= c * 1ll * (i - j))
				f[i] = min(f[j] + i - j - 1, f[i]);
		if (f[i] + n - i - 1 <= k)
			return true;
	}
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) 
		scanf("%d", &a[i]);
	l = -1;
	r = 2 * INF + 1;
	while (l < r - 1) {
		mid = (l * 1ll + r) / 2;
		if (ok(mid))
			r = mid;
		else l = mid;
	}
	printf("%d\n", r);
}