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

map <string, int> m;

string d[11];

void go(int x) {
	int y = x;
	string f;

	f.push_back(x % 10 + '0');
	x /= 10;

	while (m.count(f)) {
		f.push_back(x % 10 + '0');

		for (int i = (int)f.size() - 1; i >= 1; i--) {
			swap(f[i], f[i - 1]);
		}

		x /= 10;
	}

	m[f] = y;
}

int main() {
	int n;

	cin >> n;

	for (int i = 1989; i <= 3100; i++) {
		go(i);
	}

	d[4] = "3099";
	d[5] = "13099";
	d[6] = "113099";
	d[7] = "1113099";
	d[8] = "11113099";
	d[9] = "111113099";

	for (int i = 0; i < n; i++) {
		string s;

		cin >> s;

		string t = "";

		for (int j = 4; j < (int)s.size(); j++) {
			t.push_back(s[j]);
		}

		if (m.count(t)) {
			cout << m[t] << endl;
			continue;
		}

		if (t >= d[(int)t.size()]) {
			cout << t << endl;
		} else {
			cout << '1' << t << endl;
		}
	}

	return 0;
}