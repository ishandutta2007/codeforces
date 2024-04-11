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

const int maxn = (int)1e6 + 10;
const long long p = (int)1e9 + 7;

char s[maxn];
int v[maxn];
int z[maxn];
int len;

void go() {
	len = strlen(s);

	for (int l = 0, r = 0, i = 1; i < len; i++) {
		if (i < r) {
			z[i] = min(z[i - l], r - i);
		}

		while (i + z[i] < len && s[z[i]] == s[i + z[i]]) {
			z[i]++;
		}

		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}
}

bool check(int a, int b) {
	if (a + len <= b) {
		return true;
	}

	b -= a;

	if (b + z[b] == len) {
		return true;
	}

	return false;
}

int cnt[maxn];

int main() {
	int n, m;

	scanf("%d %d", &n, &m);

	scanf("%s", s);

	for (int i = 0; i < m; i++) {
		scanf("%d", &v[i]);
	}

	go();

	if (m != 0) {
		cnt[v[0]]++;
		cnt[v[0] + len]--;
	}

	for (int i = 1; i < m; i++) {
		if (check(v[i - 1], v[i])) {
			cnt[v[i]]++;
			cnt[v[i] + len]--;
		} else {
			printf("0");
			return 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		cnt[i] += cnt[i - 1];
	}

	long long ans = 1;

	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			ans *= 26;
			ans %= p;
		}
	}

	cout << ans;

	return 0;
}