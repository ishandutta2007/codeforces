#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <map>
#include <set>

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

int n, m;
map<string, int> cnt;
map<string, string> ans;

void run() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		set<string> cur;
		cin >> s;
		for (int L = 0; L < s.size(); ++L) {
			string m;
			for (int R = L; R < s.size(); ++R) {
				m += s[R];
				cur.insert(m);
			}
		}
		for (auto j : cur) {
			cnt[j]++;
			ans[j] = s;
		}
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		if (cnt.count(s)) {
			cout << cnt[s] << ' ' << ans[s] << '\n';
		} else {
			cout << "0 -\n";
		}
	}
}