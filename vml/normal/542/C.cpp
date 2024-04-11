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
#include <bitset>
#include <cassert>

using namespace std;

const int maxn = 210;

int f[maxn];
int cnt[maxn];
int cyc[maxn];
bool used[maxn];

long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}

	return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
	return a / gcd(a, b) * b;
}

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &f[i]);
		//f[i] = rand() % 50 + 1;
	}

	for (int i = 1; i <= n; i++) {
		memset(used, 0, sizeof used);
		int x = f[i];
		int y = f[f[i]];
		cnt[i] = 1;

		while (x != y) {
			x = f[x];
			y = f[f[y]];
			cnt[i]++;
		}

		x = f[x];
		y = f[f[y]];
		cyc[i] = 1;

		while (x != y) {
			x = f[x];
			y = f[f[y]];
			cyc[i]++;
		}

		//cout << cnt[i] << ' ' << cyc[i] << endl;
	}

	long long k = 1;

	for (int i = 1; i <= n; i++) {
		k = lcm(k, cyc[i]);
	}

	int now = 1;

	for (int i = 1; i <= n; i++) {
		if (k * now < cnt[i]) {
			now = cnt[i] / k;

			if (cnt[i] % k != 0) {
				now++;
			}
		} 
	}

	cout << k * now << endl;

	return 0;
}