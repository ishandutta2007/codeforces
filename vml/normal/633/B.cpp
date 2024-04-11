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

int main() {
	int m;

	cin >> m;
	int ans = 0;

	for (int i = 5; m > 0; i += 5) {
		int x = i;

		while (x % 5 == 0) {
			x /= 5;
			m--;
		}

		ans = i;
	}

	if (m < 0) {
		cout << '0' << endl;
		return 0;
	}

	cout << 5 << endl;

	for (int i = ans; i < ans + 5; i++) {
		cout << i << ' ';
	}

	return 0;
}