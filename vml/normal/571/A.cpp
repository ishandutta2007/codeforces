#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <memory.h>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <vector>
 
using namespace std;

long long go(long long x, long long y, long long d) {
	if (d < 0) {
		return 0;
	}

	x = min(x, d);
	y = min(y, d);

	//cout << x << ' ' << y << ' ' << d << endl;
	long long cnt = 0;

	long long f = d - y;

	if (f >= x) {
		cnt = (x + 1) * (y + 1);
	} else {
		cnt += (y + 1) * (f + 1);
		f++;
		long long l = (d - x) + 1;
		long long r = (d - f) + 1;

		cnt += r * (r + 1) / 2 - l * (l - 1) / 2;
	}

	//cout << cnt << endl;
	//exit(0);

	return cnt;
}

int get(int a, int b, int c, int l) {
	int ans = 0;
	for (int i = 0; i <= l; i++) {
		for (int j = 0; j <= l; j++) {
			for (int t = 0; t <= l; t++) {
				if (i + j + t > l) {
					break;
				}

				int aa = a + i;
				int bb = b + j;
				int cc = c + t;

				if (aa < bb + cc && bb < aa + cc && cc < aa + bb) {
					ans++;
				}
			}
		}
	}

	return ans;
}

int main() {
	int a, b, c, l;

	cin >> a >> b >> c >> l;

	long long ans = 0;

	for (int i = 0; i <= l; i++) {
		int aa = a + i;

		if (aa >= b && aa >= c) {
			if (aa - b - c + 1 <= l - i) {
				ans += go(aa - b, aa - c, l - i) - go(aa - b, aa - c, aa - b - c);
			}
		}
	}

	swap(a, b);

	for (int i = 0; i <= l; i++) {
		int aa = a + i;

		if (aa >= b && aa >= c) {
			if (aa - b - c + 1 <= l - i) {
				ans += go(aa - b, aa - c, l - i) - go(aa - b, aa - c, aa - b - c);
			}
		}
	}

	swap(a, c);

	for (int i = 0; i <= l; i++) {
		int aa = a + i;

		if (aa >= b && aa >= c) {
			if (aa - b - c + 1 <= l - i) {
				ans += go(aa - b, aa - c, l - i) - go(aa - b, aa - c, aa - b - c);
			}
		}
	}

	for (int i = max(a, b); ; i++) {
		int cnt = l - (i - a) - (i - b);

		if (cnt < 0) {
			break;
		}

		if (c > i) {
			continue;
		}

		cnt = min(cnt, i - c);

		ans -= cnt + 1;
	}

	swap(b, c);

	for (int i = max(a, b); ; i++) {
		int cnt = l - (i - a) - (i - b);

		if (cnt < 0) {
			break;
		}

		if (c > i) {
			continue;
		}

		cnt = min(cnt, i - c);

		ans -= cnt + 1;
	}

	swap(a, c);

	for (int i = max(a, b); ; i++) {
		int cnt = l - (i - a) - (i - b);

		if (cnt < 0) {
			break;
		}

		if (c > i) {
			continue;
		}

		cnt = min(cnt, i - c);

		ans -= cnt + 1;
	}

	for (int i = max(max(a, b), c); ; i++) {
		int cnt = l - (i - a) - (i - b) - (i - c);

		if (cnt < 0) {
			break;
		}

		ans++;
	}

	cout << ans << endl;

	return 0;
}