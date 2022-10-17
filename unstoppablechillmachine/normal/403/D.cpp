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
const int N = 1010;
const int LIM = 45;
int dp[N][N][LIM], pref[N][LIM], pref2[N][LIM], fact[LIM];

void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int mult(int a, int b) {
	return (a * 1ll * b) % MOD;
}

signed main() {
	fact[0] = 1;
	for (int i = 1; i < LIM; i++) {
		fact[i] = mult(fact[i - 1], i);
	}
	pref[0][0] = 1;
	for (int sum = 1; sum <= 1000; sum++) {
		for (int cnt = 0; cnt < LIM; cnt++) {
			add(pref[sum][cnt], pref[sum - 1][cnt]);
		}
	}
	for (int i = 1; i <= 1000; i++) {
		for (int sum = i; sum <= 1000; sum++) {
			for (int cnt = 1; cnt < LIM; cnt++) {
				dp[i][sum][cnt] = pref[sum - i][cnt - 1];
			}
		}
		for (int sum = i; sum <= 1000; sum++) {
			for (int cnt = 1; cnt < LIM; cnt++) {
				if (sum > i) pref2[sum][cnt] = pref2[sum - 1][cnt];
				else pref2[sum][cnt] = 0;
				add(pref2[sum][cnt], dp[i][sum][cnt]);
				add(pref[sum][cnt], pref2[sum][cnt]);
			}
		}
	}
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		if (k >= LIM) {
			cout << 0 << '\n';
		}
		else {
			cout << mult(pref[n][k], fact[k]) << '\n';
		}
	}
}