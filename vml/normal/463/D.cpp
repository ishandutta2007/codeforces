//#pragma comment (linker, "/STACK:1000000000")

#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <bitset>

using namespace std;

const int maxn = 1000 + 10, maxk = 6;
int v[maxk][maxn];
int n, k;
int d[maxn];

int dp(int x) {
	if (d[x] == 0) {
		d[x] = 1;
		for (int i = 1; i <= n; i++) {
			bool st = true;
			for (int j = 0; j < k; j++) {
				if (v[j][i] <= v[j][x]) {
					st = false;
				}
			}
			if (st) {
				d[x] = max(d[x], dp(i) + 1);
			}
		}
	}
	return d[x];
}

int main() {
	scanf("%d%d", &n, &k);

	for (int i = 0; i < k; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			scanf("%d", &x);
			v[i][x] = j;
		}
	}

	int len = 0;

	for (int i = 1; i <= n; i++) {
		len = max(dp(i), len);
	}

	cout << len;

	return 0;
}