#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6 + 1;
const int M = 1e9 + 7;

int fact[MX], fact_inv[MX];

int add(int a, int b) {
	a += b;
	return a < M ? a : a - M;
}

int mul(int a, int b) {
	return (long long)a * b % M;
}

int cnk(int n, int k) {
	return mul(fact[n], mul(fact_inv[k], fact_inv[n - k]));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1;
	fact_inv[0] = 1;
	fact_inv[1] = 1;
	for (int i = 2; i < MX; ++i) {
		fact_inv[i] = M - mul(M / i, fact_inv[M % i]);
	}
	for (int i = 1; i < MX; ++i) {
		fact_inv[i] = mul(fact_inv[i - 1], fact_inv[i]);
		fact[i] = mul(fact[i - 1], i);
	}

	int n;
	cin >> n;
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++mp[a];
	}

	int ans = 0;
	int cnt = 0;
	mp.erase(--mp.end());
	for (auto i : mp) {
		ans = add(ans, mul(i.first, mul(i.second, mul(cnk(n, cnt), mul(fact[cnt], fact[n - cnt - 1])))));
		cnt += i.second;
	}
	cout << ans << '\n';
}