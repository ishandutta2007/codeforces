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
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair

using namespace std;

const int maxn = (int)1010;
int v[maxn];
map <int, int> s;

int main() {
	int n;

	cin >> n;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		s[v[i]]++;
		if (v[i] == 0) {
			cnt++;
		}
	}
	
	sort(v, v + n);
	n = unique(v, v + n) - v;

	int ans = cnt;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map <int, int> us;
			if (i == j && s[v[i]] == 1) {
				continue;
			}

			int x = v[i];
			int y = v[j];

			if (x == 0 && y == 0) {
				continue;
			}

			us[x]++;
			us[y]++;

			int cnt = 2;

			while (s.count(x + y) && us[x + y] != s[x + y]) {
				us[x + y]++;
				swap(x, y);
				y = x + y;
				cnt++;
			}

			ans = max(ans, cnt);
		}
	}

	cout << ans << endl;

	return 0;
}