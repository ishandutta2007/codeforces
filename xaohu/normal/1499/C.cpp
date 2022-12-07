#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define ll long long
#define fi first
#define se second
using namespace std;

int T, n;
ll c, sum[2], cnt[2], mn[2];

void solve() {
	memset(sum, 0, sizeof sum);
	memset(cnt, 0, sizeof cnt);
	memset(mn, 0x3f, sizeof mn);
	cin >> n;
	ll res = 1e18;
	rep(i, 1, n) {
		cin >> c;
		int j = i & 1;
		sum[j] += c;
		cnt[j]++;
		mn[j] = min(mn[j], c);
		if (i > 1)
			res = min(res, sum[0] + sum[1] + mn[0] * (n - cnt[0]) + mn[1] * (n - cnt[1]));
	}
	cout << res << endl;
}
 
int main() {
	cin >> T;
	while (T--) solve();
	return 0;
}