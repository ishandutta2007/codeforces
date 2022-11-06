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

int dp[6][4][201][201][2];
vector<int> way[6][4][201][201][2];
vector<int> cost = {25, 25, 25, 25, 15};

void relax(int a1, int a2, int a3, int a4, int a5, int b1, int b2, int b3, int b4, int b5) {
	if (dp[b1][b2][b3][b4][b5] > dp[a1][a2][a3][a4][a5]) {
		dp[a1][a2][a3][a4][a5] = dp[b1][b2][b3][b4][b5];
		way[a1][a2][a3][a4][a5] = {b1, b2, b3, b4, b5};
	}
}

vector<pair<int, int>> ans;

void get_ans(vector<int> a) {
	vector<int> b = way[a[0]][a[1]][a[2]][a[3]][a[4]];
	if (b.size() == 0) {
		ans.pop_back();
		return;
	}
	if (a[0] != b[0]) {
		ans.back().first -= b[2];
		ans.back().second -= b[3];
		ans.pb({b[2], b[3]});
	}
	get_ans(b);
}

void run() {
	for (int t = 5; t >= 0; --t) {
		for (int L = 0; L <= t; ++L) {
			int R = t - L;
			if (L > 3 || R > 3) continue;
			for (int a = 0; a <= 200; ++a) {
				for (int b = 0; b <= 200; ++b) {
					if (L == 3 || R == 3) {
						dp[t][L][a][b][1] = -1e9;
						if (a == 0 && b == 0) {
							dp[t][L][a][b][0] = L - R;
						} else {
							dp[t][L][a][b][0] = -1e9;
						}
						continue;
					}
					dp[t][L][a][b][0] = -1e9;
					dp[t][L][a][b][1] = -1e9;
					int c = cost[t];
					if (a >= c - 2 && b >= c - 2) {
						relax(t, L, a, b, 0, t, L, a - c + 2, b - c + 2, 1);
					}
					if (a >= c) {
						for (int k = 0; k <= b && k <= c - 2; ++k) {
							relax(t, L, a, b, 0, t + 1, L + 1, a - c, b - k, 0);
						}
					}
					if (b >= c) {
						for (int k = 0; k <= a && k <= c - 2; ++k) {
							relax(t, L, a, b, 0, t + 1, L, a - k, b - c, 0);
						}
					}
					if (a >= 1 && b >= 1) {
						relax(t, L, a, b, 1, t, L, a - 1, b - 1, 1);
					}
					if (a >= 2) {
						relax(t, L, a, b, 1, t + 1, L + 1, a - 2, b, 0);
					}
					if (b >= 2) {
						relax(t, L, a, b, 1, t + 1, L, a, b - 2, 0);
					}
				}
			}
		}
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		int ans = dp[0][0][a][b][0];
		if (ans < -3) {
			cout << "Impossible\n"; 
			continue;
		} else if (ans > 0) {
			cout << 3 << ':' << 3 - ans << '\n';
		} else {
			cout << 3 + ans << ':' << 3 << '\n';
		}
		::ans = {{a, b}};
		get_ans({0, 0, a, b, 0});
		for (auto i : ::ans) {
			cout << i.first << ":" << i.second << ' ';
		}
		cout << '\n';
	}
}