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
#include <unordered_map>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair

using namespace std;
const int maxn = (int)2e5 + 10;

pair <int, int> v[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &v[i].first, &v[i].second);
	}

	sort(v, v + n);

	ll ans = 0;
	ll cnt = 1;

	for (int i = 1; i < n; i++) {
		if (v[i].first == v[i - 1].first) {
			cnt++;
		} else {
			ans += cnt * (cnt - 1) / 2;
			cnt = 1;
		}
	}

	ans += cnt * (cnt - 1) / 2;

	for (int i = 0; i < n; i++) {
		swap(v[i].first, v[i].second);
	}

	sort(v, v + n);

	cnt = 1;

	for (int i = 1; i < n; i++) {
		if (v[i].first == v[i - 1].first) {
			cnt++;
		} else {
			ans += cnt * (cnt - 1) / 2;
			cnt = 1;
		}
	}

	ans += cnt * (cnt - 1) / 2;

	cnt = 1;

	for (int i = 1; i < n; i++) {
		if (v[i] == v[i - 1]) {
			cnt++;
		} else {
			ans -= cnt * (cnt - 1) / 2;
			cnt = 1;
		}
	}

	ans -= cnt * (cnt - 1) / 2;

	cout << ans << endl;

	return 0;
}