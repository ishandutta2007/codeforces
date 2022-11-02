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
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define ui unsigned int
#define ld double

using namespace std;

int a[1000], b[1000];

bool go(int l, int r) {
	if (l == 0) {
		return a[r] == 0 && b[r] == 0;
	} else {
		return (a[r] - a[l - 1]) == 0 && (b[r] - b[l - 1]) == 0;
	}

	return false;
}

int main() {
	int n;

	cin >> n;

	string s;

	cin >> s;

	int nowa = 0;
	int nowb = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == 'U') {
			nowa++;
		} else if (s[i] == 'D') {
			nowa--;
		} else if (s[i] == 'R') {
			nowb++;
		} else {
			nowb--;
		}

		a[i] = nowa;
		b[i] = nowb;
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (go(i, j)) {
				ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}