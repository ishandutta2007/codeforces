#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define x first
#define y second
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

const int N = 1 << 18;

struct seg_tree {
	pair<long long, int> t[N * 2 + 1];

	void chg(int i, long long v, int d) {
		i += N;
		while (i > 0) {
			t[i].x += v;
			t[i].y += d;
			i >>= 1;
		}
	}

	int get1(int i, long long T, int d) {
		if (i >= N) return 0;
		i <<= 1;
		if (t[i].x * d <= T) {
			return get1(i + 1, T - t[i].x * d, d) + t[i].y;
		} else {
			return get1(i, T, d);
		}
	}

	long long get2(int i, int v) {
		if (i >= N) return 0;
		i <<= 1;
		// cout << "				" << v << ' ' << t[i].x << ' ' << t[i].y << endl;
		if (t[i].y <= v) {
			return get2(i + 1, v - t[i].y) + t[i].x;
		} else {
			return get2(i, v);
		}
	}
} box;

int n, m, t;
long long T;

void solve() {
	cin >> n >> m >> T;
	vector<pair<int, int>> res;
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		res.pb({p, i});
	}
	sort(res.begin(), res.end());
	int L = 0;
	int ans = 0, ansd = 1;
	while (L < res.size()) {
		int R = L;
		while (R < res.size() && res[L].x == res[R].x) {
			box.chg(res[R].y, res[R].x, 1);
			++R;
		}
		int f1 = box.get1(1, T, 2);
		int f2 = f1 / m * m;
		long long sum = box.get2(1, f2);
		int f3 = box.get1(1, T - sum, 1);
		// cout << res[L].x << ' ' << f1 << ' ' << f2 << ' ' << sum << ' ' << f3 << endl;
		f3 = min(f2 + m, f3);
		if (f3 > ans) {
			ans = f3;
			ansd = res[L].x;
		}
		L = R;
	}
	for (auto i : res) box.chg(i.y, -i.x, -1);
	cout << ans << ' ' << ansd << '\n';
}

void run() {
	cin >> t;
	while (t--) {
		solve();
	}
}