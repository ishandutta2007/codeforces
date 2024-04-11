#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
int f[N], rf[N];

int mult(int a, int b) {
	return (a * 1ll * b) % MOD;
}

int b_pow(int a, int b) {
	if (!b) {
		return 1;
	}
	if (b & 1) {
		return mult(a, b_pow(a, b - 1));
	}
	return b_pow(mult(a, a), b >> 1);
}

void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

void sub(int &a, int b) {
	a -= b;
	if (a < 0) {
		a += MOD;
	}
}

int C(int n, int k) {
	if (k > n) {
		return 0;
	}
	return mult(f[n], mult(rf[k], rf[n - k]));
}

int dv[310], dp[310];
vector<int> gt[N];
signed main() {
	f[0] = 1;
	for (int i = 1; i <= 1e5; i++) {
		f[i] = mult(f[i - 1], i);
	}	
	for (int i = 0; i <= 1e5; i++) {
		rf[i] = b_pow(f[i], MOD - 2);
	}
	for (int i = 1; i <= 1e5; i++) {
		vector<int> divs;
		for (int j = 1; j * j <= i; j++) {
			if (i % j == 0) {
				divs.pb(j);
				if (i / j != j) {
					divs.pb(i / j);
				}				
			}
		}
		sort(all(divs));
		vector<vector<int>> fuck(SZ(divs), vector<int>(SZ(divs)));
		for (int j = 0; j < SZ(divs); j++) {
			fuck[j][j] = 1;
			for (int k = 0; k < j; k++) {
				if (divs[j] % divs[k] == 0) {
					for (int p = 0; p <= k; p++) {
						sub(fuck[j][p], fuck[k][p]);
					}
				}
			}
		}
		gt[i] = fuck.back();
	}
	int q;
	cin >> q;
	while (q--) {
		int n, f;
		cin >> n >> f;
		vector<int> kek = gt[n];
		vector<int> divs1, divs2;
		for (int i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				divs1.pb(i);
				if (i != n / i) {
					divs2.pb(n / i);
				}
			}
		}
		while (!divs2.empty()) {
			divs1.pb(divs2.back());
			divs2.pop_back();
		}
		int ans = 0;
		for (int i = 0; i < SZ(kek); i++) {
			add(ans, mult(C(divs1[i] - 1, f - 1), kek[i]));
		}
		cout << ans << '\n';
	}
	
	cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}