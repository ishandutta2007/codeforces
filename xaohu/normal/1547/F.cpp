#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;	
using namespace std;

const int N = 400200;

int n, a[N], b[N][20];

void solve() {
	int g = 0;
	cin >> n;
	rep(i, 0, n) {
		cin >> a[i];
		g = __gcd(g, a[i]);
		a[n + i] = a[i];
	}

	rep(i, 0, 2 * n)
		b[i][0] = a[i];

	rep(j, 0, 19)
		rep(i, 0, 2 * n - (1 << j) + 1)
			b[i][j + 1] = __gcd(b[i][j], b[i + (1 << j)][j]); 
	
	auto ask = [&](int l, int r) {
		int k = 0;
		while ((1 << k) < r - l)
			k++;
		k--;
		assert((1 << k) < r - l);
		return __gcd(b[l][k], b[r - (1 << k)][k]);
	};

	int res = 0;
	rep(i, 0, n) {
		if (a[i] == g)
			continue;
		int p = i;
		per(j, 0, 20)
			if (p + (1 << j) < 2 * n && ask(i, p + (1 << j) + 1) > g)
				p += (1 << j);
		res = max(res, p - i + 1);
	}

	cout << res << "\n";
}

int main() {
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}