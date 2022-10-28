#include <bits/stdc++.h> 
using namespace std;

const int MX = 250000 + 1;

int fact[MX], M;

int add(int a, int b) {
	return (a += b) < M ? a : a - M;
}

int mul(int a, int b) {
	return 1LL * a * b % M;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n >> M;

	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = mul(fact[i - 1], i);
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = add(ans, mul(n - i + 1, mul(n - i + 1, mul(fact[n - i], fact[i]))));
	}
	cout << ans << '\n';
}