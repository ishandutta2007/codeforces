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

bool pr(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	int n;

	n = 11;
	int cnt = 0;

	int ff = 0;

	for (int i = 2; i < n; i++) {
		if (pr(i)) {
			cout << i << endl;
			ff++;
			fflush(stdout);

			string s;

			cin >> s;

			if (s[0] == 'y') {
				cnt = i;
				break;
			}
		}
	}

	if (cnt == 0) {
		cout << "prime" << endl;
		fflush(stdout);
		return 0;
	}

	cout << cnt * cnt << endl;
	fflush(stdout);
	ff++;

	string s;

	cin >> s;

	if (s[0] == 'y') {
		cout << "composite" << endl;
		return 0;
	}

	for (int i = 2; i <= 100 / cnt; i++) {
		if (i != cnt && pr(i)) {
			if (ff == 20) {
				break;
			}
			cout << i << endl;
			ff++;
			fflush(stdout);

			cin >> s;

			if (s[0] == 'y') {
				cout << "composite" << endl;
				fflush(stdout);
				return 0;
			}
		}
	}

	cout << "prime" << endl;
	fflush(stdout);

	return 0;
}