#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
const int MOD = 1e9 + 7;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

void sub(int &a, int b) {
	a -= b;
	if (a < 0) {
		a += MOD;
	}
}

signed main() {
	int n;
	cin >> n;
	vector<int> cnt((1 << 20) + 10), pw((1 << 20) + 10);
	pw[0] = 1;
	for (int i = 1; i <= 1e6; i++) {
		pw[i] = (pw[i - 1] * 2) % MOD;
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	for (int i = 0; i < 20; i++) {
		for (int mask = (1 << 20) - 1; mask > 0; mask--) {
			if ((mask >> i) & 1) {
				cnt[mask ^ (1 << i)] += cnt[mask];
			}
		}
	}
	int ans = 0;
	for (int i = 1e6; i >= 1; i--) {
		if (!cnt[i]) {
			continue;
		}
		if (__builtin_popcount(i) & 1) {
			add(ans, pw[cnt[i]] - 1);
		}
		else {
			sub(ans, pw[cnt[i]] - 1);
		}
	}
	int ans2 = pw[n] - 1;
	sub(ans2, ans);
	cout << ans2 << '\n';
}