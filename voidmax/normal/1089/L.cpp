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

void run() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> v(k);
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x--;
		v[x].pb(i);
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	vector<int> all;
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		if (v[i].empty()) {
			cnt++;
		}
		sort(v[i].begin(), v[i].end(), [&b](int A, int B) {
			return b[A] < b[B];
		});
		for (int j = 0; j < len(v[i]) - 1; j++) {
			all.pb(b[v[i][j]]);
		}
	}
	sort(all.begin(), all.end());
	ll final = 0;
	for (int j = 0; j < cnt; j++) {
		final += all[j];
	}
	cout << final << endl;
}