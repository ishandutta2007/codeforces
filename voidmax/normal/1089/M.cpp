#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define len(v) ((int)v.size())
#define x first
#define y second

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

char ans[200][200][200];

bool edge[201][201];
bool can[201][201];
bool used[201];

int cnt = 0, k = 0;
vector<int> comp[200];

void run() {
	cin >> n;
	for (int i = 0; i <= 50; ++i) {
		for (int j = 0; j <= 50; ++j) {
			for (int q = 0; q <= 50; ++q) {
				ans[i][j][q] = '.';
			}
		}
	}	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> edge[i][j];
		}
		edge[i][i] = true;
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				edge[i][j] |= edge[i][k] & edge[k][j];
			}
		}
	}
	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < n; ++j) {
	// 		cout << edge[i][j];
	// 	}
	// 	cout << endl;
	// }
	while (k < n) {
		int ans = 1e9, v = 0;
		for (int i = 0; i < n; ++i) {
			if (used[i]) continue;
			int cur = 0;
			for (int j = 0; j < n; ++j) {
				if (used[j]) continue;
				cur += edge[i][j];
			}
			if (cur < ans) v = i, ans = cur;
 		}
 		// cout << ans << ' ' << v << endl;
 		assert(ans < 1e9);
 		vector<int> cur;
 		for (int j = 0; j < n; ++j) {
 			if (used[j]) continue;
 			if (edge[v][j]) {
 				used[j] = true;
 				cur.pb(j);
 			}
 		}
 		comp[cnt++] = cur;
 		k += cur.size();
	}
	reverse(comp, comp + cnt);
	cnt = max(cnt, (n + 1) >> 1);
	// return;
	for (int i = 1; i <= cnt * 2; i += 2) {
		for (int q = 1; q < 3; ++q) {
			for (int j = 0; j <= cnt * 2; ++j) {
				ans[i][q][j] = '#';
			}
		}
	}
	for (int i = 0; i <= cnt * 2; ++i) {
		for (int j = 0; j <= cnt * 2; ++j) {
			ans[i][1][j] = '#';
		}
	}
	for (int i = 0; i <= cnt * 2; ++i) {
		for (int j = 1; j <= cnt * 2; j += 2) {
			ans[i][0][j] = '#';
		}
	}
	for (int i = 0; i < cnt; ++i) {
		ans[i * 2 + 1][0][i * 2] = '#';
		ans[i * 2][1][i * 2] = '.';
		for (int j : comp[i]) {
			ans[i * 2][2][j] = '1' + j;
		}
	}
	for (int i = 0; i < cnt; ++i) {
		for (int j = i + 1; j < cnt; ++j) {
			if (!comp[j].size()) continue;
			if (edge[comp[i][0]][comp[j][0]]) {
				ans[i * 2][1][j * 2] = '.';
			}
		}
	}
	cout << 3 << ' ' << cnt * 2 << ' ' << cnt * 2 << endl;
	for (int i = 0; i < cnt * 2; ++i) {
		for (int j = 0; j < cnt * 2; ++j) {
			for (int q = 0; q < 3; ++q) {
				cout << ans[i][q][j];
			}
			cout << '\n';
		}
		cout << '\n';
 	}
}