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
#include <memory.h>

#define ll long long
#define ld double
#define forn(i, n) for (int i = 0; i < (int)n; i++)

using namespace std;

const int maxn = (int)1e5 + 10;
pair <pair <int, int>, int> v[maxn];

bool check(pair <int, int> a, pair <int, int> b, pair <int, int> c) {
	pair <int, int> d = make_pair(a.first - b.first, a.second - b.second);
	pair <int, int> e = make_pair(c.first - b.first, c.second - b.second);

	if ((ll)d.first * e.second != (ll)e.first * d.second) {
		return false;
	}

	return true;
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &v[i].first.first, &v[i].first.second);
		v[i].second = i + 1;
	}

	sort(v, v + n);

	for (int i = 2; i < n; i++) {
		if (!check(v[i - 2].first, v[i - 1].first, v[i].first)) {
			cout << v[i - 2].second << ' ' << v[i - 1].second << ' ' << v[i].second << endl;

			return 0;
		}
	}

	return 0;
}