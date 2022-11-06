#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define x fisrt
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

int n;
int cnt, L, R;
long long ans;
vector<int> cur[4];

void run() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string g;
		int cost;
		cin >> g >> cost;
		int v = (g[1] - '0') + (g[0] - '0') * 2;
		cur[v].pb(cost);
	}
	for (int i = 0; i < 4; ++i) {
		sort(cur[i].begin(), cur[i].end());
	}
	for (int i : cur[3]) {
		ans += i;
		++L, ++R, ++cnt;
	}
	cur[3].clear();
	while (cur[1].size() && cur[2].size()) {
		ans += cur[1].back() + cur[2].back();
		cur[1].pop_back();
		cur[2].pop_back();
		++L, ++R, cnt += 2;
	}
	vector<int> res;
	for (int i = 0; i < 4; ++i) {
		for (int j : cur[i]) {
			res.pb(j);
		}
	}
	sort(res.rbegin(), res.rend());
	for (auto i : res) {
		if (cnt + 1 > L * 2) break;
		++cnt;
		ans += i;
	}
	cout << ans << '\n';
}