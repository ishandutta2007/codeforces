#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int bin[65];
long long pure[65];

long long calpure(long long p, long long bar) {
	long long ret = bar - (1 << (p - 1)) + 1;
//cout << p << ' ' << bar << ' ' << ret << endl;
	if (ret <= 0) return 0;
	for (int rp = 1; rp < p; ++rp) {
		if (p % rp == 0) {
			long long a = bar;
			int r = 0;
			while (a) {
				++r;
				a >>= rp;
			}
			a = bar;
			for (int k = 1; k < r; ++k) a >>= rp;
			for (int k = r - 2; k >= 0; --k) {
				long long tt = (bar >> (k * rp)) % (1ll << rp);
				if (tt > a) {
					break;
				} else if (tt < a) {
					--a;
					break;
				}
			}
			ret -= calpure(rp, a);
		}
	}
//cout << p << ' ' << bar << "==" << ret << endl;
	return ret;
}

long long cal(long long t) {
	if (t == 0) return 0;
	long long a = t, minm, sum;
	int len = 0;
	while (a) {
		bin[++len] = a % 2;
		a /= 2;
	}
//for (int i = len; i >= 1; --i) cout << bin[i];
//cout << endl;
	sum = 0;
	for (int p = 1; p < len; ++p) {
		for (int r = 2; r * p <= len; ++r) {
			if (p * r < len) {
				sum += pure[p];
			} else {
				a = t;
				for (int k = 1; k < r; ++k) a >>= p;
				for (int k = r - 2; k >= 0; --k) {
					long long tt = (t >> (k * p)) % (1ll << p);
					if (tt > a) {
						break;
					} else if (tt < a) {
						--a;
						break;
					}
				}
				sum += calpure(p, a);
//cout << t << endl;
//cout << a << ' ' << p << ' ' << calpure(p, a) << endl;
			}
//cout << p << ' ' << r << ' ' << sum << endl;
		}
	}
	return sum;
}

void check(long long l, long long r) {
	int cnt = 0;
	for (int i = l; i <= r; ++i) {
		for (int p = 1; (1ll << p) <= i; ++p) {
			int tmp = 1;
			int t = i, o = i % (1ll << p);
			if (o < (1 << (p - 1))) continue;
			while (t) {
				if (t % (1 << p) != o) tmp = 0;
				t >>= p;
			}
			if (tmp) {
//cout << i << ' ' << p << endl;
				++cnt;
				break;
			}
		}
	}
	cout << cnt << endl;
//	for (int i = l - 1; i <= r + 1; ++i) if (cal(i) > cal(i - 1)) cout << i << endl;
//cout << cal(r) << ' ' << cal(l - 1) << endl;
}


int main() {
	for (int i = 1; i <= 60; ++i) {
		pure[i] = calpure(i, (1ll << i) - 1);
	}	
	long long l, r;
	cin >> l >> r;
	cout << cal(r) - cal(l - 1) << endl;
	return 0;
}