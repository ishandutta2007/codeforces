#pragma comment (linker, "/STACK:1000000000")

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <string>

using namespace std;

const int maxn = (int)2e5 + 10;

char s[maxn], t[maxn];

bool rav(int l, int r, int l1, int r1) {
	int n = r - l + 1;
	for (int i = 0; i < n; i++) {
		if (s[l + i] != t[l1 + i]) {
			return false;
		}
	}

	return true;
}

bool check(int l, int r, int l1, int r1) {
	if (((r - l + 1) & 1) == 1) {
		return rav(l, r, l1, r1);
	}

	int m = (l + r) >> 1;
	int m1 = (l1 + r1) >> 1;

	if (check(l, m, l1, m1)) {
		return check(m + 1, r, m1 + 1, r1);
	} else {
		return check(l, m, m1 + 1, r1) && check(m + 1, r, l1, m1);
	}
}

int main() {
	scanf("%s %s", &s, &t);

	int n = strlen(s);

	if (check(0, n - 1, 0, n - 1)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}