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
#include <stdio.h>
  
using namespace std;

int n;
const int maxn = (int)1e5 + 10;
int v[maxn];
bool used[maxn];
int sz[maxn];
int num[maxn];

int go(int pos, int now) {
	used[pos] = true;
	num[pos] = now & 1;

	if (used[v[pos]]) {
		sz[pos] = now;
		return now;
	}

	sz[pos] = go(v[pos], now + 1);
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (i == v[i]) {
			printf("YES\n");

			for (int j = 1; j <= n; j++) {
				if (i != j) {
					printf("%d %d\n", i, j);
				}
			}

			exit(0);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			go(i, 1);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (sz[i] == 2) {
			for (int j = 1; j <= n; j++) {
				if (sz[j] % 2 == 1) {
					printf("NO\n");
					return 0;
				}
			}

			printf("YES\n");
			printf("%d %d\n", i, v[i]);

			for (int j = 1; j <= n; j++) {
				if (j != i && j != v[i]) {
					if (num[j] == 1) {
						printf("%d %d\n", j, i);
					} else {
						printf("%d %d\n", j, v[i]);
					}
				}
			}

			return 0;
		}
	}

	printf("NO\n");

	return 0;
}