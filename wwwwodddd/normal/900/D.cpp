#include <bits/stdc++.h>
using namespace std;
int p = 1000000007;
int pw(int x, int y) {
	int re = 1;
	for (; y > 0; y >>= 1) {
		if (y & 1) {
			re = (long long)re * x % p;
		}
		x = (long long)x * x % p;
	}
	return re;
}

int mu(int x) {
	int re = 1;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			x /= i;
			re = -re;
			if (x % i == 0) {
				return 0;
			}
		}
	}
	if (x > 1) {
		re = -re;
	}
	return re;
}

int main() {
	int x, y;
	scanf("%d%d", &x, &y);
	if (y % x != 0) {
		printf("0\n");
		return 0;
	}
	y /= x;
	vector<int> a;
	for (int i = 1; i * i <= y; i++) {
		if (y % i == 0) {
			a.push_back(i);
			if (i * i < y) {
				a.push_back(y / i);
			}
		}
	}
	sort(a.begin(), a.end());
	long long ans = 0;
	for (int i: a) {
//		cerr << i << ' ' << mu(i) << endl;
		ans += mu(i) * pw(2, y / i - 1);
		ans %= p;
		if (ans < 0) {
			ans += p;
		}
	}
	cout << ans << endl;
}