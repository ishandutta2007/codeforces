#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

long long a, b, c, w, x;

long long cal1(long long t) {
	long long d = b - x * t;
	if (d >= 0) {
		return a;
	} else {
		long long e = (-d + w - 1) / w;
		return a - e;
	}
}

long long cal2(long long t) {
	return c - t;
}

bool check(long long t) {
	return cal1(t) >= cal2(t);
}

int main() {
	cin >> a >> b >> w >> x >> c;
	long long l = 0, r = 2000000000000ll;
	if (check(l)) {
		cout << 0 << endl;
	} else {
		long long m;
		while (l < r) {
			m = l + r >> 1;
			if (check(m)) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		cout << l << endl;
	}
	return 0;
}