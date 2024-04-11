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

int n, k;
int lst;
vector<pair<pair<int, int>, int>> cur;
vector<int> a;

int get_cur_q(int lst) {
	int v1 = (200 * lst + n) / (n * 2);
	// cout << 100. * lst / n << ' ' << v1 << ' ' << v2 << endl;
	// cout << abs(v1 * n * n - 100 * lst) << ' ' << abs(v2 * n * n - 100 * lst) << endl;
	return v1;
}

bool cool[2001];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	// n = 6;
	// cout << get_cur_q(1) << endl;
	// return 0;
	cin >> n >> k;
	a.resize(n);
	cin >> a;
	reverse(a.begin(), a.end());
	int ans = 0;
	while (cur.size() || a.size()) {
		int q = get_cur_q(lst);
		while (k && a.size()) {
			cur.pb({{1, a.back()}, a.size()});
			a.pop_back();
			--k;
		}
		// cout << " " << q << endl;
		for (auto i : cur) {
			if (i.x.x == q) {
				cool[i.y] = true;
				// cout << i.y << endl;
			}
		}
		for (int i = 0; i < cur.size(); ++i) {
			if (cur[i].x.x == cur[i].x.y) {
				swap(cur[i], cur.back());
				cur.pop_back();
				--i;
				++k;
				++lst;
			} else {
				++cur[i].x.x;
			}
		}
	}
	for (int i = 0; i < 2000; ++i) {
		if (cool[i]) {
			++ans;
		}
	}
	cout << ans << '\n';
}