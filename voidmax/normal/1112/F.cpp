#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define len(a) int(a.size())
#define read(FILENAME) freopen(((string)FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen(((string)FILENAME + ".out").c_str(), "w", stdout)
using namespace std;

template<typename T1, typename T2>
inline void chkmin(T1 &x, const T2 &y) {
	if (x > y) x = y;
} 


template<typename T1, typename T2>
inline void chkmax(T1 &x, const T2 &y) {
	if (x < y) x = y;
} 

template<typename T>
inline istream &operator >>(istream &_in, vector<T> &a) {
	for (auto &i : a) _in >> i;
	return _in;
}

template<typename T>
inline ostream &operator <<(ostream &_out, const vector<T> &a) {
	bool OK = false;
	for (auto &i : a) {
		if (OK) _out << ' ';
		OK = true;
		cout << i;
	}
	return _out;
}

template<typename T>
inline ostream &operator <<(ostream &_out, const set<T> &a) {
	bool OK = false;
	for (auto &i : a) {
		if (OK) _out << ' ';
		OK = true;
		cout << i;
	}
	return _out;
}

template<typename T>
inline ostream &operator <<(ostream &_out, const unordered_set<T> &a) {
	bool OK = false;
	for (auto &i : a) {
		if (OK) _out << ' ';
		OK = true;
		cout << i;
	}
	return _out;
}

template<typename T1, typename T2>
inline ostream &operator <<(ostream &_out, const map<T1, T2> &a) {
	bool OK = false;
	for (auto &i : a) {
		if (OK) _out << ", ";
		OK = true;
		cout << "{" << a.x << ":" << a.y << "}";
	}
	return _out;
}


template<typename T1, typename T2>
inline ostream &operator <<(ostream &_out, const unordered_map<T1, T2> &a) {
	bool OK = false;
	for (auto &i : a) {
		if (OK) _out << ", ";
		OK = true;
		cout << "{" << a.x << ":" << a.y << "}";
	}
	return _out;
}

template<typename T1, typename T2>
inline istream &operator >>(istream &_in, pair<T1, T2> &a) {
	_in >> a.x >> a.y;
	return _in;
}

template<typename T1, typename T2>
inline ostream &operator <<(ostream &_out, const pair<T1, T2> &a) {
	_out << a.x << ' ' << a.y;
	return _out; 
}

typedef long long base;
typedef pair<int, int> point;

const int N = 2e5 + 1;

int n;
vector<int> edge[N];
int cost[N];

long long dp[N][2];

bool cool[N];

void dfs1(int i, int p = -1) {
	dp[i][1] = 0;
	vector<long long> val;
	for (int j : edge[i]) {
		if (j == p) continue;
		dfs1(j, i);
		dp[i][1] += dp[j][1];
		val.pb(dp[j][1] - dp[j][0]);
	}
	if (val.size()) {
		auto v = *max_element(val.begin(), val.end());
		dp[i][0] = dp[i][1] - v;
		chkmin(dp[i][1], dp[i][0] + cost[i]);
	} else {
		dp[i][0] = 0;
		dp[i][1] = cost[i];
	}
	// cout << i + 1 << ' ' << dp[i][0] << ' ' << dp[i][1] << endl;
}

bool can[N][2];

void dfs2(int i, int p = -1) {
	// cout << i + 1 << ' ' << can[i][0] << ' ' << can[i][1] << endl;
	long long cur1 = 0;
	vector<long long> val;
	for (int j : edge[i]) {
		if (j == p) continue;
		cur1 += dp[j][1];
		val.pb(dp[j][1] - dp[j][0]);
	}
	if (val.size()) {
		auto v = *max_element(val.begin(), val.end());
		long long cur0 = cur1 - v;
		// cout << "?" << i + 1 << ' ' << cur1 << ' ' << dp[i][1] << endl;
		if (can[i][1] && cur1 == dp[i][1]) {
			for (int j : edge[i]) {
				if (j == p) continue;
				can[j][1] = true;
				// cout << "?" << j + 1 << endl;
			}
		}
		vector<int> who;
		for (auto j : edge[i]) {
			if (j == p) continue;
			if (dp[j][1] - dp[j][0] == v) {
				who.pb(j);
			}
		}
		if (can[i][0]) {
			if (who.size() == 1) {
				for (int j : edge[i]) {
					if (j == p || who[0] == j) continue;
					can[j][1] = true;
				}
			} else {
				for (int j : edge[i]) {
					if (j == p) continue;
					can[j][1] = true;
				}
			}
			for (int j : who) {
				can[j][0] = true;
			}
		}
		// cout << "?" << i + 1 << ':' << cur0 + cost[i] << ' ' << dp[i][1] << endl;
		if (can[i][1] && dp[i][1] == cur0 + cost[i]) {
			cool[i] = true;
			if (who.size() == 1) {
				for (int j : edge[i]) {
					if (j == p || who[0] == j) continue;
					can[j][1] = true;
				}
			} else {
				for (int j : edge[i]) {
					if (j == p) continue;
					can[j][1] = true;
				}
			}
			for (int j : who) {
				can[j][0] = true;
			}
		}
	} else {
		if (can[i][1]) cool[i] = true;
	}
	for (int j : edge[i]) {
		if (j == p) continue;
		dfs2(j, i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> cost[i];
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		edge[a].pb(b);
		edge[b].pb(a);
	}
	dfs1(0);
	can[0][1] = true;
	dfs2(0);
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (cool[i]) {
			ans.pb(i + 1);
		}
	}
	cout << dp[0][1] << ' ' << ans.size() << '\n';
	cout << ans << '\n';
}