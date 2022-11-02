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

set <string> a[2];

void go(int tp, string s);

void add(int tp, string s, int x, int y) {
	swap(s[x], s[y]);
	go(tp, s);
}

void go(int tp, string s) {
	if (a[tp].count(s)) {
		return;
	}

	a[tp].insert(s);
	if (s[0] == 'X') {
		add(tp, s, 0, 1);
		add(tp, s, 0, 2);
	} else if (s[1] == 'X') {
		add(tp, s, 1, 0);
		add(tp, s, 1, 3);
	} else if (s[2] == 'X') {
		add(tp, s, 2, 0);
		add(tp, s, 2, 3);
	} else {
		add(tp, s, 3, 1);
		add(tp, s, 3, 2);
	}
}

int main() {
	string s;
	string t;
	string k;

	cin >> s;
	cin >> k;

	s = s + k;

	cin >> t;
	cin >> k;

	t = t + k;

	go(0, s);
	go(1, t);

	for (auto it = a[0].begin(); it != a[0].end(); it++) {
		if (a[1].count(*it)) {
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;

	return 0;
}