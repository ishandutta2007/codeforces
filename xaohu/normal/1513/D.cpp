#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define vi vector<int>

using namespace std;

const int N = 200111;

int t, n, p, a[N], vis[N];
pair<int, int> b[N];

int main() {
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> p;
		FOR(i, n) {
			cin >> a[i];
			vis[i] = 0;
			b[i] = {a[i], i};
		}
		sort(b, b + n);
		long long res = 0;
		FOR(i, n) {
			int c = b[i].first;
			if (c > p) break;
			int p = b[i].second, l = p, r = p;
			while (r + 1 < n && !vis[r] && a[r + 1] % a[p] == 0) r++;
			while (l > 0 && !vis[l - 1] && a[l - 1] % a[p] == 0) l--;
			rep(j, l, r - 1) {
				vis[j] = 1;
				res += c;
			}
		}
		res += 1ll * p * count(vis, vis + n - 1, 0);
		cout << res << "\n";
	}	
	return 0;
}