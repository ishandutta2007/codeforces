#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define vi vector<int>

using namespace std;

const int N = 100111;
const int P = 1e9 + 7;

int power(int a, int b) {
	int res = 1;
	for (; b; b /= 2, a = 1ll * a * a % P)
		if (b & 1)
			res = 1ll * res * a % P;
	return res;
}

int n, fac[N];
long long s;
map<int, int> m;

int C(int n, int k) {
	return 1ll * fac[n] * power(fac[k], P - 2) % P * power(fac[n - k], P - 2) % P;
}

int main() {
	cin.tie(0);
	cin >> n;
	FOR(i, n) {
		int a;
		cin >> a;
		s += a;
		m[a]++;
	}
	if (s % n) {
		cout << "0\n";
		return 0;
	}
	fac[0] = 1;
	FOR(i, N - 1)
		fac[i + 1] = 1ll * fac[i] * (i + 1) % P;
	long long ans = 1;
	int cnt0 = 0, cnt1 = 0;
	for (auto [a, b] : m) {
		if (a == s / n) {
			ans = ans * C(n, b) % P;
			continue;
		}
		if (a < s / n) 
			cnt0 += b;
		else
			cnt1 += b;
		ans = ans * power(fac[b], P - 2) % P;
	}
	ans = ans * fac[cnt0] % P * fac[cnt1] % P;
	int nn = n - m[s / n];
	if (cnt0 == 1 || cnt1 == 1) {
		cout << ans * nn % P;
		return 0;
	}
	if (nn) 
		ans = 2 * ans % P;
	cout << ans << "\n";
	return 0;
}