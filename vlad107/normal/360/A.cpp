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
#define INFINF 1000000000000000000LL
#define N 500500

using namespace std;

long long a[N], b[N], mt;
int n, tq[N], tl[N], tr[N], td[N], l, r, d, q, m;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		a[i] = INF;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d%d", &q, &l, &r, &d);
		--l;
		--r;
		if (q == 1) {
			for (int j = l; j <= r; j++) {
				a[j] += d;
				b[j] += d;
			}
		} else {
			for (int j = l; j <= r; j++)
				if (d < a[j])
					a[j] = d;
		}
		tq[i] = q;
		tl[i] = l;
		tr[i] = r;
		td[i] = d;
	}
	for (int i = 0; i < n; i++) {
		a[i] -= b[i];
		b[i] = a[i];
	}
	for (int i = 0; i < m; i++) {
		q = tq[i];
		l = tl[i];
		r = tr[i];
		d = td[i];
		if (q == 1) {
			for (int j = l; j <= r; j++)
				a[j] += d;
		} else {
			long long mt = -INFINF;
			for (int j = l; j <= r; j++)
				if (a[j] > mt)
					mt = a[j];
			if (mt != d) {
				puts("NO");
				return 0;
			}
		}
	}
	for (int i = 0; i < n; i++)
		if ((b[i] < -INF) || (b[i] > INF)) {
			puts("NO");
			return 0;
		}
	puts("YES");
	for (int i = 0; i < n; i++)
		cout << b[i] << " ";
	puts("");
}