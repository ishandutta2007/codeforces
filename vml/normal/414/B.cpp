#pragma comment (linker, "/STACK:1000000000")

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

const int p = 1000000007;
const int MAX_N = 2010;
const int MAX_K = 2010;

int res[MAX_K][MAX_N];

int rec(int pos, int last) {
	if (res[pos][last] == -1) {
		if (pos == 0) {
			res[pos][last] = 1;
		} else {
			int ans = 0;
			for (int i = 1; i * i <= last; i++) {
				if (last % i == 0) {
					if (i * i == last) {
						ans = (ans + rec(pos - 1, i)) % p;
					} else {
						ans = (ans + rec(pos - 1, i)) % p;
						ans = (ans + rec(pos - 1, last / i)) % p;
					}
				}
			}
			res[pos][last] = ans;
		}
	}
	return res[pos][last];
}

int main() {
	for (int i = 0; i < MAX_K; i++) {
		for (int j = 0; j < MAX_N; j++) {
			res[i][j] = -1;
		}
	}
	int n, k;
	scanf("%d %d", &n, &k);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = (ans + rec(k - 1, i)) % p;
	}
	printf("%d", ans);
	return 0;
}