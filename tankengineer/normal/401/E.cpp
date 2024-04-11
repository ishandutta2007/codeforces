#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

long long n, m, l, r, p;

const int N = 100005;
int f[N];

#define div DIV

long long cnt, sum;
vector<int> div;

long long lb, rb;

void go(int i, long long mul, int sym) {
	if (mul > rb) {
		return;
	}
	if (i == div.size()) {
		long long t1 = rb / mul, t2 = (lb - 1) / mul;
		(cnt += sym * (t1 - t2) % p) %= p;
		(sum += sym * ((t1 * (t1 + 1) / 2) - (t2 * (t2 + 1) / 2)) % p * mul % p) %= p;
	} else {
		go(i + 1, mul, sym);
		go(i + 1, mul * div[i], -sym);
	}
}

int main() {
	f[1] = 1;
	for (int i = 2; i < N; ++i) {
		if (f[i] == 0) {
			f[i] = i;
			for (long long j = (long long)i * i; j < N; j += i) {
				f[j] = i;
			}
		}
	}
	cin >> n >> m >> l >> r >> p;
	long long ans = 0;
	if (l <= 1 && r >= 1) {
		ans = ((long long)(n + 1) * m % p + (long long)(m + 1) * n % p) % p;
	}
	for (long long dx = 1; dx <= n && dx <= r; ++dx) {
		long long ll = 1, rr = l, mm;
		while (ll < rr) {
			mm = ll + rr >> 1;
			if (mm * mm + dx * dx >= l * l) {
				rr = mm;
			} else {
				ll = mm + 1;
			}
		}
		lb = ll;
		ll = 0, rr = r + 1;
		while (ll < rr) {
			mm = ll + rr + 1 >> 1;
			if (mm * mm + dx * dx > r * r) {
				rr = mm - 1;
			} else {
				ll = mm;
			}
		}
		rb = min(m, ll);
		if (lb > rb) {
			continue;
		}
		div.clear();
		int d = dx;
		while (d != 1) {
			int c = f[d];
			div.push_back(c);
			while (d % c == 0) {
				d /= c;
			}
		}

		cnt = 0, sum = 0;
		go(0, 1, 1);
		long long b = ((m + 1) * cnt % p - sum) % p;
		(ans += 2 * (n - dx + 1) % p * b % p) %= p;
	}
	if (ans < 0) {
		ans += p;
	}
	cout << ans << endl;
	return 0;
}