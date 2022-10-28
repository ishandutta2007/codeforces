#include <bits/stdc++.h>
using namespace std;

const int M = (119 << 23) + 1;

int add(int a, int b) {
	a += b;
	return a < M ? a : a - M;
}

int mul(int a, int b) {
	return (long long)a * b % M;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> pows2(n, 1);
	for (int i = 1; i < n; ++i) {
		pows2[i] = add(pows2[i - 1], pows2[i - 1]);
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		ans = add(ans, mul(add(pows2[n - i], mul(n - i, pows2[n - i - 1])), a));
	}
	cout << ans << '\n';
}