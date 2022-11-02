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
#include <numeric>
#include <memory.h>
#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define ui unsigned int
#define ld double
#define pll pair <ll, ll> 
 
using namespace std;

const int maxn = (int)1e6 + 10;
int v[maxn];

int main() {
	int n, q;

	cin >> n >> q;

	int pos = 0;
	int pos1 = 1;

	while (q--) {
		int tp;

		scanf("%d", &tp);

		if (tp == 2) {
			if ((pos & 1) == 0) {
				pos++;
				if (pos == n) {
					pos = 0;
				}
			} else {
				pos--;
				if (pos == -1) {
					pos = n - 1;
				}
			}

			if ((pos1 & 1) == 0) {
				pos1++;
				if (pos1 == n) {
					pos1 = 0;
				}
			} else {
				pos1--;
				if (pos1 == -1) {
					pos1 = n - 1;
				}
			}

		} else {
			int x;

			scanf("%d", &x);

			pos += x;
			pos1 += x;

			if (pos >= n) {
				pos -= n;
			}

			if (pos < 0) {
				pos += n;
			}

			if (pos1 >= n) {
				pos1 -= n;
			}

			if (pos1 < 0) {
				pos1 += n;
			}
		}
	}

	int now = 0;

	for (int i = pos; i < pos + n; i += 2) {
		int x = i;

		if (x >= n) {
			x -= n;
		}

		v[x] = now;
		now += 2;
	}

	now = 1;

	for (int i = pos1; i < pos1 + n; i += 2) {
		int x = i;

		if (x >= n) {
			x -= n;
		}

		v[x] = now;
		now += 2;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", v[i] + 1);
	}

	return 0;
}