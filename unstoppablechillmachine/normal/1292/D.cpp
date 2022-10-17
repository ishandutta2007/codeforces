#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll

const int MX = 5000; 
const int INF = 1e9 + 10;
int cnt[MX + 1][MX + 1], coef[MX + 1], ptr[MX + 1], c[MX + 1];
bool killed[MX + 1];

vector<pair<int, int>> factorize(int n) {
	vector<pair<int, int>> res;
	for (int i = 2; i * i <= n; i++) {
		int cnt = 0;
		while (n % i == 0) {
			cnt++;
			n /= i;
		}
		if (cnt) {
			res.pb({i, cnt});
		}
	}
	if (n > 1) {
		res.pb({n, 1});
	}
	return res;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 2; i <= MX; i++) {
		for (int j = 2; j <= MX; j++) {
			cnt[i][j] = cnt[i - 1][j];
		}
		vector<pair<int, int>> kek = factorize(i);
		for (auto it : kek) {
			cnt[i][it.F] += it.S;
		}
		ptr[i] = MX;
	}
	//cout << "OK" << endl;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		coef[x]++;
	}
	for (int i = 1; i <= MX; i++) {
		if (!coef[i]) {
			killed[i] = true;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= MX; i++) {
		if (coef[i]) {
			for (int j = 1; j <= MX; j++) {
				ans += coef[i] * 1ll * cnt[i][j];
			}
		}
	}
	for (;;) {
		for (int i = 1; i <= MX; i++) {
			c[i] = 0;
		}
		for (int i = 1; i <= MX; i++) {
			if (!killed[i]) {
				while (ptr[i] > 1 && cnt[i][ptr[i]] == 0) {
					ptr[i]--;
				}
				if (ptr[i] == 1) {
					killed[i] = true;
				}
				else {
					c[ptr[i]] += coef[i];
				}
			}
		}
		int x = -1;
		for (int i = 1; i <= MX; i++) {
			if (c[i] * 2 > n) {
				x = i;
				break;
			}
		}
		if (x == -1) {
			break;
		}
		int mn = INF;
		for (int i = 1; i <= MX; i++) {
			if (ptr[i] != x) {
				killed[i] = true;
			}
			if (!killed[i]) {
				mn = min(mn, cnt[i][ptr[i]]);
			}
		}
		ans -= (2 * c[x] - n) * mn;
		for (int i = 1; i <= MX; i++) {
			if (!killed[i]) {
				cnt[i][ptr[i]] -= mn;
			}
		}
	}
	cout << ans << '\n';
}