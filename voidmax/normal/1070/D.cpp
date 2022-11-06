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

int n, k;
long long ans;
vector<int> a;

void run() {
	cin >> n >> k;
	a.resize(n);
	cin >> a;
	reverse(a.begin(), a.end());
	a.pb(0);
	for (int i = 0; i < n; ++i) {
		if (a[i] < 0) a[i] = 0;
		ans += a[i] / k;
		a[i] %= k;
		if (a[i]) {
			++ans;
			a[i + 1] -= k - a[i];
		}
	}
	cout << ans << '\n';
}