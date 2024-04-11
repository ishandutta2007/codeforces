#include <bits/stdc++.h>
using namespace std;
const int MOD = (119 << 23) + 1;

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	vector<long long> ans(n + 1);
	long long mx = 1, sum1 = 0, sum2 = 0;
	for (int i = 1; i <= n; ++i) {
		(mx *= 10) %= MOD;
		ans[i] = i * mx % MOD;
		((ans[i] -= sum1) += MOD) %= MOD;
		(sum1 += ans[i]) %= MOD;
		(sum2 += ans[i]) %= MOD;
		(sum1 += sum2) %= MOD;
	}
	for (int i = n; i; --i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}