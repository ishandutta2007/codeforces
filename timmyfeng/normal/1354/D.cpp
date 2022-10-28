#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e6 + 1;

int ft[MX], logn, n;

void upd(int a, int val) {
	for ( ; a <= n; a += a & -a) {
		ft[a] += val;
	}
}

int nth(int a) {
	int res = 0, cur = 0;
	for (int i = logn - 1; i >= 0; --i) {
		if (res + (1 << i) <= n && cur + ft[res + (1 << i)] < a) {
			res += 1 << i;
			cur += ft[res];
		}
	}
	return res + 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> n >> q;
	logn = 32 - __builtin_clz(n);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		upd(a, 1);
	}

	for (int i = 0; i < q; ++i) {
		int b;
		cin >> b;
		if (b > 0) {
			upd(b, 1);
		} else {
			upd(nth(-b), -1);
		}
	}

	int ans = nth(1);
	cout << (ans > n ? 0 : ans) << '\n';
}