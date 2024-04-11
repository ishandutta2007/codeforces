#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 1;
const int MXK = 100 + 2;
const int M = (119 << 23) + 1;

struct mint {
	int x;
	mint() {}
	mint(int x) : x(x) {}
	mint operator+=(mint oth) { x += oth.x; if (x >= M) { x -= M; } return *this; }
	mint operator-=(mint oth) { x -= oth.x; if (x < 0) { x += M; } return *this; }
	mint operator*=(mint oth) { x = (long long)x * oth.x % M; return *this; }
	mint operator++() { return *this += 1; }
	mint operator--() { return *this -= 1; }
	mint operator-() { return mint(0) -= *this; }
	//mint operator/=(mint oth) { return x *= modinv(oth.x, M); }
};
ostream& operator<<(ostream& os, mint a) { return os << a.x; }
bool operator==(mint a, mint b) { return a.x == b.x; }
bool operator!=(mint a, mint b) { return a.x != b.x; }
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint operator*(mint a, mint b) { return a *= b; }
//mint operator/(mint a, mint b) { return a /= b; }

mint dp[MX][MXK], dptot[MX];
int a[MX], _freq[MXK];
int* freq = _freq + 1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k, len;
	cin >> n >> k >> len;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	dptot[0] = 1;
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (i > len) {
			--freq[a[i - len]];
			cnt -= !freq[a[i - len]];
		}
		cnt += !freq[a[i]];
		++freq[a[i]];
		for (int j = 1; j <= k; ++j) {
			if (a[i] == -1 || a[i] == j) {
				dp[i][j] = dptot[i - 1];
			}
			if (i >= len && (freq[-1] > 0) + (freq[j] > 0) == cnt) {
				dp[i][j] -= dptot[i - len] - dp[i - len][j];
			}
			dptot[i] += dp[i][j];
		}
	}
	cout << dptot[n] << '\n';
}