#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <memory.h>
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define ui unsigned int
#define ld double

using namespace std;

const int maxn = 10010;

int v[maxn];
int cnt[maxn];
int sum[maxn];
int summ[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v, v + n);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			cnt[v[j] - v[i]]++;
		}
	}

	ll ans = 0;

	ll x = n * (n - 1) / 2;

	for (int i = 0; i < maxn; i++) {
		if (cnt[i] != 0) {
			ll sum = 0;
			int pos = 0;

			for (int j = i - 1; j >= 0; j--) {
				while (pos < i - j) {
					sum += cnt[pos];
					pos++;
				}

				ans += sum * cnt[i] * cnt[j];
			}
		}
	}

	printf("%.10lf", (ld)ans / x / x / x);

	return 0;
}