#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)

using namespace std;

int n, l, r, cnt[1 << 20][2];

void solve() {
	cin >> n >> l >> r;
	rep(i, 1, n)
		cnt[i][0] = cnt[i][1] = 0;
	rep(i, 1, n) {
		int x;
		cin >> x;
		cnt[x][(i > l)]++;
	}
	int sum[2] {};
	rep(i, 1, n) {
		int c = min(cnt[i][0], cnt[i][1]);
		cnt[i][0] -= c;
		cnt[i][1] -= c;
		sum[0] += cnt[i][0];
		sum[1] += cnt[i][1];
	}
	int id = (sum[1] > sum[0]);
	int need = abs(sum[0] - sum[1]);
	int ans = 0;
	rep(i, 1, n) {
		while (need >= 2 && cnt[i][id] >= 2) {
			need -= 2;
			ans++;
			cnt[i][id] -= 2;
		}
	}
	cout << ans + min(sum[0], sum[1]) + need << "\n";
	
}

int main() {
	int t;
	cin >> t;
	while (t--) 
		solve();
	
	return 0;
}