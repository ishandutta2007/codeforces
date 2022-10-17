#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
//#define int ll

const int MOD = 998244353;
const int N = 2e5 + 10;

int a[N], f[N], rf[N];

void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int mult(int a, int b) {
	return (a * 1ll * b) % MOD;
}

int b_pow(int a, int b) {
	if (!b) {
		return 1;
	}
	if (b & 1) {
		return mult(b_pow(a, b - 1), a);
	}
	return b_pow(mult(a, a), b >> 1);
}

int C(int n, int k) {
	if (n < 0 || k < 0 || k > n) {
		return 0;
	}
	return mult(f[n], mult(rf[k], rf[n - k]));
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	f[0] = 1;
	for (int i = 1; i <= 2e5; i++) {
		f[i] = mult(f[i - 1], i);
	}
	for (int i = 0; i <= 2e5; i++) {
		rf[i] = b_pow(f[i], MOD - 2);
	}
	int n, k;
	cin >> n >> k;
	/*if (k == 1) {
		cout << 0 << '\n';
		exit(0);	
	}*/
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int x = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i + 1]) {
			x++;
		}
	}
	if (a[n] != a[1]) {
		x++;
	}
	int sum = 0;
	for (int kek = 0; kek < x; kek++) {
		int ost = x - kek;
		if (ost & 1) {
			add(sum, mult(b_pow(k - 2, kek), mult(C(x, ost), b_pow(2, ost - 1))));
		}
		else {
			int flex = b_pow(2, ost) - C(ost, ost / 2);
			if (flex < 0) {
				flex += MOD;
			}
			flex = mult(flex, b_pow(2, MOD - 2));
			add(sum, mult(b_pow(k - 2, kek), mult(C(x, ost), flex)));
		}
	}
	for (int i = 0; i < n - x; i++) {
		sum = mult(sum, k);
	}
	cout << sum << '\n';
}