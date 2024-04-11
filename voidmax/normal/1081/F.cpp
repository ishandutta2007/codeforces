// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
// #pragma GCC optimize("unroll-loops")    
#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((string(FILENAME) + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((string(FILENAME) + ".out").c_str(), "w", stdout)
using namespace std;
        
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; } 
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
template<typename T, typename U> inline istream &operator>> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) { if (_v.empty()) { return _out; } _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline istream &operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
        
typedef long long base; 
typedef pair<int, int> point;      
typedef complex<double> comp;

int n;
bool rev = false;
bitset<301> a, b;

int cur;


int ask(int L, int R) {
	cout << "? " << L << ' ' << R << endl;
	int cnt = 0;
	cin >> cnt;
	if (rev) cnt = n - cnt;
	return cnt;
}

int pref(int L) {
	int R = n - (L % 2);
	int ans;
	if (L + 1 > R - 1) {
		ans = ask(R, L);
	} else {
		rev = !rev;
		ans = ask(L + 1, R - 1);
	}
	if ((L + ans - cur) & 1) {
		cur = ans;
		for (int i = R; i <= n; ++i) {
			a[i] = !a[i];
			b[i] = !b[i];
		}
		return pref(L);
	}
	for (int i = 1; i <= L; ++i) {
		a[i] = !a[i];
		b[i] = !b[i];
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	srand(time(0));
	cin >> n >> cur;
	if (n == 1) {
		cout << "! " << cur << endl;
		return 0;
	}
	for (int i = 1; i + 1 <= n - 2 * (n & 1); ++i) {
		int ncur = pref(i);
		int k = 0;
		for (int j = 1; j < i; ++j) {
			k += a[j];
		}
		if (ncur - k + (i - k) == cur) {
			a[i] = 0;
		} else {
			a[i] = 1;
		}
		cur = ncur;
	}
	if (n & 1) {
		while (true) {
			int ans = ask(n - 2, n - 1);
			if ((ans - cur) & 1) {
				for (int i = n - 2; i <= n; ++i) {
					a[i] = !a[i];
					b[i] = !b[i];
				}
				cur = ans;
				continue;
			}
			for (int i = 1; i <= n - 1; ++i) {
				a[i] = !a[i];
				b[i] = !b[i];
			}
			int v = (ans - cur + n - 1) >> 1;
			a[n] = ans - v;
			cur = ans;
			break;
		}
		while (true) {
			int ans = ask(n - 1, n);
			if ((ans - cur) & 1) {
				for (int i = 1; i <= n; ++i) {
					a[i] = !a[i];
					b[i] = !b[i];
				}
				cur = ans;
				continue;
			}
			for (int i = n - 1; i <= n; ++i) {
				a[i] = !a[i];
				b[i] = !b[i];
			}
			int v = (ans - cur + 2) >> 1;
			a[n - 1] = v - a[n];
			cur = ans;
			break;
		}
		a[n - 2] = 0;
		for (int i = 1; i <= n; ++i) {
			cur -= a[i];
		}
		a[n - 2] = cur;
	} else {
		for (int i = 1; i < n; ++i) {
			cur -= a[i];
		}
		a[n] = cur;
	}
	cout << "! ";
	for (int i = 1; i <= n; ++i) {
		cout << (a[i] ^ b[i]);
	}
	cout << endl;
}