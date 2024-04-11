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

int n, m;
int dist[501][501];
vector<int> ne[501];

const int N = 5e5;

int lst = 1;
vector<int> val[N];
int root[N];
vector<int> edge[N];

void solve(int i) {
	// cout << val[i] << endl;
	int ansv = val[i][0], cnt = 1e9;
	for (int j : val[i]) {
		int max_ans = 0;
		for (int q : ne[j]) {
			int cur = 0;
			for (int v : val[i]) {
				if (dist[j][v] == 1 + dist[q][v]) {
					++cur;
				}
			}
			max_ans = max(max_ans, cur);
		}
		if (max_ans < cnt) {
			cnt = max_ans;
			ansv = j;
		}
	}
	// cout << "?" << ansv << ' ' << cnt << endl;
	root[i] = ansv;
	for (int q : ne[ansv]) {
		vector<int> cur;
		for (int v : val[i]) {
			if (dist[ansv][v] == 1 + dist[q][v]) {
				cur.pb(v);
			}
		}
		// cout << "!" << cur << endl;
		if (cur.size() == 0) {
			edge[i].pb(-1);
		} else {
			edge[i].pb(lst);
			val[lst] = cur;
			++lst;
		}
	}
	for (int j : edge[i]) {
		if (j == -1) continue;
		solve(j);
	}
}

void run() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dist[i][j] = 1e9;
		}
		dist[i][i] = 0;
	}
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		vector<int> elem;
		elem.resize(k);
		cin >> elem;
		// elem.pb(elem[0]);
		for (int j = 0; j < k; ++j) --elem[j];
		for (int j = 0; j + 1 < k; ++j) {
			dist[elem[j + 1]][elem[j]] = dist[elem[j]][elem[j + 1]] = 1;
		}
	}	
	vector<int> all;
	for (int i = 0; i < n; ++i) {
		all.pb(i);
	}
	val[0] = all;
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (dist[i][j] == 1) {
				ne[i].pb(j);
			}
		}
	}
	solve(0);
	for (int i = 0; i < n; ++i) {
		int res = 0;
		while (true) {
			cout << root[res] + 1 << endl;
			string s;
			cin >> s;
			if (s[0] == 'F') {
				break;
			}
			int k;
			cin >> k;
			--k;
			for (int j = 0;; ++j) { 
				if (ne[root[res]][j] == k) {
					res = edge[res][j];
					break;
				}
			}
		}
	}
}