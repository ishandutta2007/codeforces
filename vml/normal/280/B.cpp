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

const int maxn = (int)1e5 + 10;
int v[maxn];
vector <pair <int, int> > t;
vector <pair <int, int> > h;

bool go(int l, int r, int x) {
	bool st = true;

	for (int i = l; i <= r; i++) {
		if ((v[i] & (1 << x)) == 0) {
			st = false;
			break;
		}
	}

	if (st) {
		h.push_back(make_pair(l, r));
		return false;
	}

	st = true;

	for (int i = l; i <= r; i++) {
		if ((v[i] & (1 << x)) != 0) {
			st = false;
			break;
		}
	}

	if (st) {
		h.push_back(make_pair(l, r));
		return false;
	}

	int now = 0;
	int left = l;

	for (int i = l; i <= r; i++) {
		if ((v[i] & (1 << x)) != 0) {
			now++;

			if (now == 1) {
				if (left != i) {
					h.push_back(make_pair(left, i));
					left = i;
					now = 1;
				}
			}

			if (now == 2) {
				if (left != i - 1) {
					//cout << x << ' ' << left << ' ' << i - 1 << endl;
					h.push_back(make_pair(left, i - 1));
					h.push_back(make_pair(left + 1, i));
				}
				now = 1;
				left = i;
			}
		}
	}

	if (left != r) {
		h.push_back(make_pair(left, r));
	}

	return true;
}

int get(int l, int r, int x) {
	int pos = l;

	for (int i = l; i <= r; i++) {
		if ((v[i] & (1 << x)) != 0) {
			pos = i;
			break;
		}
	}

	int ans = 0;

	set <int> s;

	for (int i = pos + 1; i <= r; i++) {
		s.insert(v[i]);

		ans = max(ans, v[pos] ^ (*s.rbegin()));
	}

	s.clear();

	for (int i = pos - 1; i >= l; i--) {
		s.insert(v[i]);

		ans = max(ans, v[pos] ^ (*s.rbegin()));
	}

	return ans;
}

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	t.push_back(make_pair(0, n - 1));
	int f = -1;

	for (int i = 30; i >= 0; i--) {
		bool st = false;
		for (int j = 0; j < (int)t.size(); j++) {
			if (go(t[j].first, t[j].second, i)) {
				st = true;
				break;
			}
		}
		t = h;
		h.clear();

		if (st) {
			f = i;
			break;
		}
	}

	if (f == -1) {
		printf("0");
		return 0;
	}

	int ans = 0;

	for (int i = 0; i < (int)t.size(); i++) {
		ans = max(ans, get(t[i].first, t[i].second, f));
	}

	cout << ans << endl;

	return 0;
}