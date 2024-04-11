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

int main() {
	string s;

	getline(cin, s);

	int x = 0;
	int t = 1;

	while ('0' <= s.back() && s.back() <= '9') {
		x += t * (s.back() - '0');
		t *= 10;
		s.pop_back();
	}

	int cnt1 = 1;
	int cnt2 = 0;

	for (int i = 2; s[i] != '='; i += 4) {
		if (s[i] == '-') {
			cnt2++;
		} else {
			cnt1++;
		}
	}

	int z = cnt1 - x;

	z = max(z, cnt2);

	if (z > x * cnt2) {
		cout << "Impossible" << endl;
		return 0;
	}

	int z2 = x + z;

	if (z2 > x * cnt1) {
		cout << "Impossible" << endl;
		return 0;
	}

	vector <int> a, b;

	while (cnt1 != 0) {
		a.push_back(min(x, z2 - cnt1 + 1));
		cnt1--;
		z2 -= a.back();
	}

	while (cnt2 != 0) {
		b.push_back(min(x, z - cnt2 + 1));
		cnt2--;
		z -= b.back();
	}

	cout << "Possible" << endl;

	cout << a.back() << ' ';
	a.pop_back();

	for (int i = 2; s[i] != '='; i += 4) {
		if (s[i] == '+') {
			cout << s[i] << ' ';
			cout << a.back() << ' ';
			a.pop_back();
		} else {
			cout << s[i] << ' ';
			cout << b.back() << ' ';
			b.pop_back();
		}
	}

	cout << '=' << ' ' << x << endl;

	return 0;
}