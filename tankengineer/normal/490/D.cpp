#include<cassert>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int a, b, c, d;

pair<int, pair<int, int> > shrink (int a) {
	int c2 = 0, c3 = 0;
	while (a % 2 == 0) {
		a /= 2;
		++c2;
	}
	while (a % 3 == 0) {
		a /= 3;
		++c3;
	}
	return make_pair(a, make_pair(c2, c3));
}

int ans;

void cut2(int &a, int &b, int cnt) {
	while (cnt) {
		if (a % 2 == 0) {
			a /= 2;
		} else {
			assert(b % 2 == 0);
			b /= 2;
		}
		--cnt;
		++ans;
	}
}

void cut3t1(int &a, int &b, int cnt) {
	while (cnt) {
		if (a % 3 == 0) {
			a /= 3;
		} else {
			assert(b % 3 == 0);
			b /= 3;
		}
		--cnt;
		ans += 2;
	}
}

void cut3t2(int &a, int &b, int cnt) {
	while (cnt) {
		if (a % 3 == 0) {
			a /= 3;
			a *= 2;
		} else {
			assert(b % 3 == 0);
			b /= 3;
			b *= 2;
		}
		--cnt;
		++ans;
	}
}

int main() {
	scanf("%d%d%d%d", &a, &b, &c, &d);
	pair<int, pair<int, int> > aa = shrink(a), bb = shrink(b), cc = shrink(c), dd = shrink(d);
	if ((long long)aa.first * bb.first != (long long)cc.first * dd.first) {
		printf("-1\n");
	} else {
		ans = 0;
		int delta2 = aa.second.first + bb.second.first - cc.second.first - dd.second.first,
			delta3 = aa.second.second + bb.second.second - cc.second.second - dd.second.second;
		bool reversed = false;
		if (delta2 < 0 || (delta2 == 0 && delta3 < 0)) {
			delta2 = -delta2;
			delta3 = -delta3;
			reversed = true;
		}
		if (delta3 < 0) {
			int mins = min(delta2, -delta3);
			delta2 -= mins;
			delta3 += mins;
			if (!reversed) {
				cut3t2(c, d, mins);
			} else {
				cut3t2(a, b, mins);
			}
			if (delta2 == 0) {
				reversed = !reversed;
				delta3 = -delta3;
			}
		}
		if (delta3 >= 0) {
			if (!reversed) {
				cut2(a, b, delta2);
				cut3t1(a, b, delta3);
			} else {
				cut2(c, d, delta2);
				cut3t1(c, d, delta3);
			}
			delta2 = 0;
			delta3 = 0;
		}
		printf("%d\n%d %d\n%d %d\n", ans, a, b, c, d);
		assert((long long)a * b == (long long)c * d);
	}
	return 0;
}