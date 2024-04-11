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
#define pii pair<int, int>
#define ll long long
#define ui unsigned int
#define ld double

using namespace std;

const int maxn = (int)1e5 + 10;
char s[maxn];
int v[maxn];

int n;

int go(int pos, int x) {
	int l = max(0, pos - x);
	int r = min(n - 1, pos + x);

	if (l == 0) {
		return v[r];
	}

	return v[r] - v[l - 1];
}

int main() {
	int k;

	cin >> n >> k;

	scanf("%s", s);

	int cnt = 0;

	int now = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			now++;
		}

		v[i] = now;
	}

	int l = 1;
	int r = n;

	while (l != r) {
		int m = (l + r) / 2;

		bool st = false;

		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				if (go(i, m) >= k + 1) {
					st = true;
					break;
				}
			}
		}

		if (st) {
			r = m;
		} else {
			l = m + 1;
		}
	}

	cout << l << endl;

	return 0;
}