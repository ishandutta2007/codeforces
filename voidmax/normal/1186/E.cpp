// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("unroll-loops")    
#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define len(a) int(a.size())
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

const int N = 1e6 + 5;

int n, m, q;
int cnt[2001][2001];

long long get2(int x, int y);

long long get(long long x, long long y) {
	if (x == 0 || y == 0) return 0;
	if (x <= n && y <= m) return cnt[x][y];
	if (x * m > y * n) {
		long long v = x / n;
		if (v <= 0) exit(0);
		while (v & (v - 1)) v &= (v - 1);
		if (v == 1) return get(x - (x % n), y) + get2(x % n, y);
		else        return get2(x - v * n, y) + v * n * y / 2;
	} else {
		long long v = y / m;
		if (v <= 0) exit(0);
		while (v & (v - 1)) v &= (v - 1);
		if (v == 1) return get(x, y - (y % m)) + get2(x, y % m);
		else        return get2(x, y - v * m) + v * m * x / 2;
	}
}

long long get2(int x, int y) {
	return 1LL * x * y - get(x, y);
} 

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		char c;
    		cin >> c;
    		cnt[i + 1][j + 1] = c - '0';
    		cnt[i + 1][j + 1] += cnt[i][j + 1] + cnt[i + 1][j] - cnt[i][j]; 
    	}
    }
    while (q--) {
    	int a, b, c, d;
    	cin >> a >> b >> c >> d;
    	--a, --b;
    	// swap(a, b);
    	// swap(c, d);
    	long long rep = get(c, d) - get(c, b) - get(a, d) + get(a, b);
    	cout << rep << '\n';
    }
}