#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

const int N = 1 << 20;

struct fenwick {
	ll f[N];

	void add(int x, ll d) {
		if (!x) return;
		for (; x < N; x += x & -x)
			f[x] += d;
	}

	ll query(int x) {
		ll res = 0;
		for (; x > 0; x -= x & -x)
			res += f[x];
		return res;
	}

	ll range(int l, int r) {
		return query(r) - query(l - 1);
	}
} cnt, sum, T;

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	ll res = 0;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;

		res += x * i;
		res -= T.query(x);

		for (int j = 0; j <= 300000; j += x) {
			res += sum.range(j, j + x - 1) - j * cnt.range(j, j + x - 1);
			T.add(j, j);
			T.add(j + x, -j);
		}

		sum.add(x, x);
		cnt.add(x, 1);

		cout << res << " ";
	}
	return 0;
}