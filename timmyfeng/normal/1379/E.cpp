#include <bits/stdc++.h>
using namespace std;

int cur;

bool possible(int n, int k) {
	if (n % 2 == 0)
		return false;
	if ((n & (n + 1)) == 0) {
		if (k == 0)
			return true;
		else if (k == 1)
			return false;
	}
	if (n == 9 && k == 2)
		return false;
	return k > 0 && k < n / 2;
}

void dfs(int n, int k, int p) {
	cout << p << " ";
	int u = ++cur;
	if (n == 1)
		return;

	for (int l = 1; l < n; l = l * 2 + 1) {
		int r = n - l - 1;
		int kr = k - (max(l, r) > min(l, r) * 2);
		if (possible(l, 0) && possible(r, kr)) {
			dfs(l, 0, u);
			dfs(r, kr, u);
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	if (!possible(n, k)) {
		cout << "NO\n";
		exit(0);
	}

	cout << "YES\n";
	dfs(n, k, 0);
}