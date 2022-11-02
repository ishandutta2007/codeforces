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

using namespace std;

const int N = 5e5;

int n, x[N], y[N];

int main() {
//	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);
	int idx = 1;
	long long dst = -1;
	for (int i = 1; i < n; i++) {
		long long cur = (x[i] - x[0]) * 1LL * (x[i] - x[0]) + (y[i] - y[0]) * 1LL * (y[i] - y[0]);
		if ((dst == -1) || (cur < dst)) {
			dst = cur;
			idx = i;
		}
	}
	long long mn = -1;
	long long vx = y[idx] - y[0];
	long long vy = x[0] - x[idx];
	int nom;
	for (int i = 1; i < n; i++) {
		if (i == idx) continue;
		long long cur = vx * 1LL * (x[i] - x[0]) + vy * 1LL * (y[i] - y[0]);
		if (abs(cur) == 0) continue;
//		cerr << i << ": " << cur << endl;
		if ((abs(cur) < mn) || (mn == -1)) {
			mn = abs(cur);
			nom = i;
		}
	}
	printf("%d %d %d\n", 1, 1 + idx, nom + 1);
}