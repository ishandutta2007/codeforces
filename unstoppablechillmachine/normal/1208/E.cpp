#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int N = 1e6 + 10;
int arr[N], pref[N], suf[N];
ll ans[N], lol[N];
const int INF = 1e9 + 10;

signed main() {
	int n, w;
	cin >> n >> w;
	for (int i = 1; i <= n; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 1; j <= cnt; j++) {
			cin >> arr[j];
			if (j >= 2) pref[j] = max(pref[j - 1], arr[j]);
			else {
				pref[j] = arr[j];
			}
		}
		suf[cnt] = arr[cnt];
		for (int j = cnt - 1; j >= 1; j--) {
			suf[j] = max(suf[j + 1], arr[j]);
		}
		deque<pair<int, int>> d;
		int L = INF, R = -INF;
		for (int j = 1; j <= w; j++) {
			if (j <= cnt) {
				while (!d.empty() && d.back().F < arr[j]) {
					d.pop_back();
				}
				d.pb({arr[j], j});
			}
			if (j <= cnt) {
				while (j - d.front().S > w - cnt) {
					d.pop_front();
				}
				if (w - cnt + 1 > j) {
					ans[j] += max(0, d.front().F);
				}
				else {
					ans[j] += d.front().F;
				}
			}
			else {
				int can = min(cnt, w - j + 1);
				if (can == cnt) {
					L = j;
					break;
				}
				ans[j] += max(0, suf[cnt - can + 1]);
			}
		}
		if (L == INF) {
			continue;
		}
		for (int j = w; j >= 1; j--) {
			int can = min(cnt, w - j + 1);
			if (can == cnt) {
				R = j;
				break;
			}
			ans[j] += max(0, suf[cnt - can + 1]);
		}
		if (L <= R) {
			lol[L] += max(0, pref[cnt]);
			lol[R + 1] -= max(0, pref[cnt]);
		}
	}
	ll cur = 0;
	for (int i = 1; i <= w; i++) {
		cur += lol[i];
		ans[i] += cur;
	}
	for (int i = 1; i <= w; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	//cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}