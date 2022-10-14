#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N, K1, K2, W, B; cin >> N >> K1 >> K2 >> W >> B;
	int nW = min(K1, K2) + abs(K1 - K2) / 2;
	K1 = N - K1;
	K2 = N - K2;
	int nB = min(K1, K2) + abs(K1 - K2) / 2;
	cout << (nW >= W && nB >= B ? "YES" : "NO") << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--)
		solve();
	return 0;
}