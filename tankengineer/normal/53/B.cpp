#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

long long ansh, ansy;

void update(long long h, long long w) {
	if (h * w > ansh * ansy || h * w == ansh * ansy && h > ansh) {
		ansh = h;
		ansy = w;
	}
}

int main() {
	long long h, w;
	cin >> h >> w;
	ansh = 0, ansy = 0;
	for (int i = 0; (1ll << i) <= max(h, w); ++i) {
		long long e = 1ll << i, f;
		if (h >= e) {
			if (4 * e > 5 * w) {
				continue;
			}
			if (5 * e < 4 * w) {
				f = 5 * e / 4;
			} else {
				f = w;
			}
			update(e, f);
		}
		if (w >= e) {
			if (5 * h < 4 * e) {
				continue;
			}
			if (4 * h > 5 * e) {
				f = 5 * e / 4;
			} else {
				f = h;
			}
			update(f, e);
		}
	}
	cout << ansh << ' ' << ansy;
	return 0;
}