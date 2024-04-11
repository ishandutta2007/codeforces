#include <bits/stdc++.h>
#define FOR(i, a) for (int i = 0; i < a; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

const int P = 998244353;

int power(int a, int b) {
	int res = 1;
	for (; b; b /= 2, a = 1ll * a * a % P)
		if (b & 1) res = 1ll * res * a % P;
	return res;
}

int n, m, ans;
string s[300111], t[300111];

int solve() {
	int cnt = 0;
	int sum[300111] {};
	FOR(i, n) {
		int prv = 0;
		FOR(j, m) {
			if (s[i][j] == '*') {
				prv = 0;
				continue;
			}
			if (j + 1 < m && s[i][j + 1] == 'o')
				sum[prv]++;
			prv++;
			cnt++;
		}
	}
	int res = 0, cur = 0;
	for (int i = 0; i + 2 <= cnt; i++) {
		if (i & 1)
			cur = (cur + power(2, cnt - i - 2)) % P;
		res = (res + 1ll * (cur + (i % 2 == 0 ? power(2, cnt - i - 2) : 0)) * sum[i]) % P;
	}
	return res;
}

int main() {
	cin >> n >> m;
	FOR(i, n)
		cin >> s[i];
	ans = solve();
	FOR(i, m)
		t[i].resize(n, 'a');
	FOR(i, n)
		FOR(j, m)
			t[j][i] = s[i][j];
	FOR(i, m)
		s[i] = t[i];
	swap(n, m);
	cout << (ans + solve()) % P;
	return 0;
}