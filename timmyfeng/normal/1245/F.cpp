#include <bits/stdc++.h>
using namespace std;

int ct(int a, int b) {
	int res = 0, zer = 0;
	for (int i = 1; i <= b; i *= 2) {
		if (b & i) {
			b ^= i;
			if (!(a & b)) {
				res += 1 << zer;
			}
		}
		if (!(a & i)) {
			++zer;
		}
	}
	return res;
}

long long solve(int a, int b) {
	if (!a) return 2 * b - 1 + solve(1, b);
	if (a == b) return 0;
	if (a % 2) return 2 * (ct(a, b) - ct(a, a)) + solve(a + 1, b);
	if (b % 2) return 2 * (ct(b - 1, b) - ct(b - 1, a)) + solve(a, b - 1);
	return 3 * solve(a / 2, b / 2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << solve(a, b + 1) << '\n';
	}
}