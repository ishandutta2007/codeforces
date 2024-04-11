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

int n, m, k;
bool cool[1001];
vector<int> p;
vector<int> who[1001];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	cin >> n >> m >> k;
	p.resize(n);
	cin >> p;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		who[t].pb(i);
	}
	for (int i = 0; i < k; ++i) {
		int a;
		cin >> a;
		cool[a - 1] = true;
	}
	for (int i = 1; i <= m; ++i) {
		sort(who[i].begin(), who[i].end(), [](int i, int j) {return p[i] > p[j];});
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < who[i].size(); ++j) {
			if (cool[who[i][j]] && j != 0) ++ans;
		}
	}
	cout << ans << '\n';
}