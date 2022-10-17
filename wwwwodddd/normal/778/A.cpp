#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
string p, t;
int n;
int a[1000020];
bool v[1000020];
bool check(int x) {
	memset(v, 0, sizeof v);
	for (int i = 0; i < x; i++) {
		v[a[i]] = true;
	}

	int r = 0;
	for (int i = 0; i < n; i++) {
		if (v[i]) {
			continue;
		}
//		printf("%c", t[i]);
		if (t[i] == p[r]) {
			r++;
		}
		if (r == p.size()) {
			return true;
		}
	}
//	printf("\n");
	return false;
}
int main() {
	cin >> t;
	cin >> p;
	n = t.size();
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	int L = 0;
	int R = n + 1;
	while (L < R - 1) {
		int M = (L + R) / 2;
		if (check(M)) {
			L = M;
		} else {
			R = M;
		}
	}
	cout << L << endl;
	return 0;
}