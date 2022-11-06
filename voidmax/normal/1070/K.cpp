#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

#define int long long
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
	vector<int> v(n);
	int sm = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sm += v[i];
	}
	if (sm % k != 0) {
		cout << "No" << endl;
		return;
	}
	int one = sm / k;
	int cur = 0;
	int cnt = 0;
	vector<int> rez;
	for (int i = 0; i < n; i++) {
		cur += v[i];
		cnt++;
		if (cur % one == 0) {
			k--;
			cur = 0;
			rez.pb(cnt);
			cnt = 0;
		}
	}
	if (k == 0) {
		cout << "Yes" << endl;
		for (int x : rez) {
			cout << x << " ";
		}
	} else {
		cout << "No" << endl;
	}
}