#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
#include <cassert>

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define len(v) ((int)v.size())

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
	for (T x : v) {
		os << x << " ";
	}
	return os;
}

template <class T>
istream &operator>>(istream &is, vector<T> &v) {
	for (T &x : v) {
		is >> x;
	}
	return is;
}

void run();

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	run();
}

int cnt[26];
bitset<301> can3;
bitset<3001> can2;
bitset<30001> can;

void bag_without_(int i, int n) {
	if (n > 3000) {
		can.reset();
		can[0] = true;
		for (int j = 0; j < 26; ++j) {
			if (j == i) continue;
			can |= can << cnt[j];
		}
	} else if (n > 300) {
		can2.reset();
		can2[0] = true;
		for (int j = 0; j < 26; ++j) {
			if (j == i) continue;
			can2 |= can2 << cnt[j];
		}
	} else {
		can3.reset();
		can3[0] = true;
		for (int j = 0; j < 26; ++j) {
			if (j == i) continue;
			can3 |= can3 << cnt[j];
		}
	}
}

int n, m, k;

void solve() {
	cin >> n >> m >> k;
	for (int i = 0; i < 26; ++i) cnt[i] = 0;
	string s;
	cin >> s;
	for (auto c : s) cnt[c - 'A']++;
	long long ans = 4e18;
	for (int i = 0; i < 26; ++i) {
		if (!cnt[i]) continue;
		bag_without_(i, n);
		for (int L = max(0, n - cnt[i]); L <= n; ++L) {
			if (n > 3000) {
				if (!can[L]) continue;
			} else if (n > 300) {
				if (!can2[L]) continue;
			} else {
				if (!can3[L]) continue;
			}
			int R = k - L - cnt[i];
			if (R < 0) continue;
			int bL = n - L;
			int bR = n + m - L - bL - R;
			// cout << bL << ' ' << bR << endl;
			if (1LL * bL * bR < 0) {
				ans = 0;
				break;
			}
			ans = min(ans, 1LL * bL * bR);
		}		
	}
	cout << ans << '\n';
}

void run() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}