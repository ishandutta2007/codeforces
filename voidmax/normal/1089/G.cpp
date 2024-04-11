#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define len(v) ((int)v.size())

using namespace std;
#define int long long
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
const int N = 7;

void solve() {
	int k;
	cin >> k;
	vector<int> v(N);
	int one = 0;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		one += v[i];
	}

	int final = 1e18;
	for (int st = 0; st < N; st++) {
		int full = max(0LL, (k / one) - 3);
		int p = k - one * full;
		int L = full * 7;
		if (p) {
			for (int j = st; p; j++) {
				p -= v[j % N];
				L++;
			}
		}
		final = min(final, L);
	}
	cout << final << "\n";
}

void run() {
	int cnt_tests;
	cin >> cnt_tests;
	for (int test = 0; test < cnt_tests; test++) {
		solve();
	}
}