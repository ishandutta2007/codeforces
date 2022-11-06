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

int n;

void run() {
	cin >> n;
	int m = n;
	vector<int> p;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			p.pb(i);
			while (n % i == 0) {
				n /= i;
			}
		}
	}
	if (n != 1) p.pb(n);
	if (p.size() < 2) {
		cout << "NO\n";
		return;
	}
	int ansL = 0, ansR = 1;
	n = m - p[1] - 1;
	while (n % p[0]) {
		n -= p[1];
		++ansR;
	}
	ansL = n / p[0];
	cout << "YES\n2\n";
	cout << ansL << " " << m / p[0] << endl;
	cout << ansR << " " << m / p[1] << endl;

}