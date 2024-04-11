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

int n;

void test() {
	string s;
	cin >> s;
	long long ans = 1e18;
	for (int t = 0; t < 5; ++t) {
		int Lx = 0, Rx = 0, Ly = 0, Ry = 0;
		int x = 0, y = 0;
		for (auto i : s) {
			if (i == 'W') ++x;
			if (i == 'S') --x;
			if (i == 'A') ++y;
			if (i == 'D') --y;
			chkmin(Lx, x);
			chkmin(Ly, y);
			chkmax(Rx, x);
			chkmax(Ry, y);
		}
		string old = s;
		x = 0, y = 0;
		for (int j = 0; j < s.size(); ++j) {
			char i = s[j];
			if (i == 'W') ++x;
			if (i == 'S') --x;
			if (i == 'A') ++y;
			if (i == 'D') --y;
			if (t == 1 && x && Lx == x) {
				s.insert(s.begin() + j, 'W');
				break;
			}
			if (t == 2 && x && Rx == x) {
				s.insert(s.begin() + j, 'S');
				break;
			}
			if (t == 3 && y && Ly == y) {
				s.insert(s.begin() + j, 'A');
				break;
			}
			if (t == 4 && y && Ry == y) {
				s.insert(s.begin() + j, 'D');
				break;
			}
		}
		Lx = 0, Rx = 0, Ly = 0, Ry = 0;
		x = 0, y = 0;
		for (auto i : s) {
			if (i == 'W') ++x;
			if (i == 'S') --x;
			if (i == 'A') ++y;
			if (i == 'D') --y;
			chkmin(Lx, x);
			chkmin(Ly, y);
			chkmax(Rx, x);
			chkmax(Ry, y);
		}
		swap(old, s);
		chkmin(ans, 1LL * (Ry - Ly + 1) * (Rx - Lx + 1));
	}
	// cout << s << endl;
	cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    cin >> n;
    while (n--) {
    	test();
    }
}