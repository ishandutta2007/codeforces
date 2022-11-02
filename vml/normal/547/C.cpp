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
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
 
using namespace std;

const int maxn = (int)5e5 + 10;
int v[maxn];
int cnt[maxn];
bool used[maxn];
int f[maxn];

int go(int x) {
	int cnt = 0;
	int f = 0;

	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			while (x % i == 0) {
				x /= i;
				f++;
			}
		}
	}

	if (x != 1) {
		f++;
	}

	return f % 2;
}

int gen(int x) {
	int y = 1;

	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			y *= i;
			while (x % i == 0) {
				x /= i;
			}
		}
	}

	y *= x;

	return y;
}

int main() {
	for (int i = 2; i < maxn; i++) {
		f[i] = go(i);
	}

	int n, q;

	scanf("%d %d", &n, &q);

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		v[i] = gen(v[i]);
	}

	long long last_ans = 0;
	int count = 0;

	for (int i = 0; i < q; i++) {
		int x;
		long long d = 0;

		scanf("%d", &x);
		x--;

		if (!used[x]) {
			used[x] = true;
			x = v[x];
			
			for (int j = 1; j * j <= x; j++) {
				if (x % j == 0) {
					int a = j;

					if (f[a] == 1) {
						d += cnt[a];
					} else {
						d -= cnt[a];
					}

					if (x / j != a) {
						a = x / j;

						if (f[a] == 1) {
							d += cnt[a];
						} else {
							d -= cnt[a];
						}
					}
				}
			}
			last_ans += count - d;
			count++;

			for (int j = 1; j * j <= x; j++) {
				if (x % j == 0) {
					if (j != 1) {
						cnt[j]++;
					}

					if (x / j != j) {
						cnt[x / j]++;
					}
				}
			}
		} else {
			used[x] = false;
			x = v[x];

			for (int j = 1; j * j <= x; j++) {
				if (x % j == 0) {
					if (j != 1) {
						cnt[j]--;
					}

					if (x / j != j) {
						cnt[x / j]--;
					}
				}
			}

			for (int j = 1; j * j <= x; j++) {
				if (x % j == 0) {
					int a = j;

					if (f[a] == 1) {
						d += cnt[a];
					} else {
						d -= cnt[a];
					}

					if (x / j != a) {
						a = x / j;

						if (f[a] == 1) {
							d += cnt[a];
						} else {
							d -= cnt[a];
						}
					}
				}
			}
			count--;
			last_ans -= count - d;
		}

		printf("%I64d\n", last_ans);
	}

	return 0;
}