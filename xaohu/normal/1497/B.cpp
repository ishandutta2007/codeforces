#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
using namespace std;	

int t, n, m, cnt[100111];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(cnt, 0, sizeof cnt);
		while (n--) {
			int x;
			cin >> x;
			cnt[x % m]++;
		}
		int ans = 0;
		rep(a, 0, m / 2) {
			int b = (m - a) % m;
			if (a == b) {
				ans += (cnt[a] > 0);
				continue;
			}
			if (cnt[a] > cnt[b])
				swap(cnt[a], cnt[b]);
			if (cnt[b]) 
				ans += 1 + max(0, cnt[b] - (cnt[a] + 1));
		}
		cout << ans << "\n";
	}
	return 0;
}