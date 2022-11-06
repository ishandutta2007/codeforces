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
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")    
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <complex>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#include <iomanip> 
#include <chrono>
#include <fstream>
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

const int N = 1e5 + 1;
const int S = 1 << 17;
const int LOG = 18;

struct seg_tree {
	int t[S * 2 + 1];

	void init() {
		for (int i = S; i--;) {
			t[i] = max(t[i * 2], t[i * 2 + 1]);
		}
	}
	
	int get(int i, int L, int R, int Ln, int Rn) {
		if (Ln <= L && R <= Rn) {
			return t[i];
		}
		if (Rn <= L || R <= Ln) {
			return -1e9;
		}
		int M = (L + R) >> 1;
		return max(get(i * 2, L, M, Ln, Rn), get(i * 2 + 1, M, R, Ln, Rn));
	}
} L[LOG], R[LOG];

int n;

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	int a;
    	cin >> a;
    	L[0].t[i + S] = a - i;
    	R[0].t[i + S] = a + i; 
    }
    if (n == 1) {
    	cout << 0 << endl;
    	return 0;
    }
    L[0].init();
    R[0].init();
    for (int lg = 0; lg + 1 < LOG; ++lg) {
    	for (int i = 0; i < n; ++i) {
    		int Ln = L[lg].t[i + S] + i, Rn = R[lg].t[i + S] - i;
    		int newLn = Ln, newRn = Rn;
    		if (Ln + Rn + 1 < n) {
    			for (int t = -1; t <= 1; ++t) {
    				int Lask = max(n * t, i - Ln);
    				int Rask = min(n * (t + 1) - 1, i + Rn);
    				if (Lask > Rask) continue;
    				int ansL = L[lg].get(1, 0, S, Lask - (n * t), Rask + 1 - (n * t));
    				int ansR = R[lg].get(1, 0, S, Lask - (n * t), Rask + 1 - (n * t));
    				chkmax(newLn, ansL - n * t + i);
    				chkmax(newRn, ansR + n * t - i);
    			}
    		}
    		L[lg + 1].t[i + S] = newLn - i;
    		R[lg + 1].t[i + S] = newRn + i;
    	}
    	L[lg + 1].init();
    	R[lg + 1].init();
    }
    for (int i = 0; i < n; ++i) {
    	int ans = 1;
    	int L = -i, R = i;
    	for (int lg = LOG; lg--;) {
    		int Ln = L + i, Rn = R - i;
    		int newLn = Ln, newRn = Rn;
			for (int t = -1; t <= 1; ++t) {
				int Lask = max(n * t, i - Ln);
				int Rask = min(n * (t + 1) - 1, i + Rn);
				if (Lask > Rask) continue;
				int ansL = ::L[lg].get(1, 0, S, Lask - (n * t), Rask + 1 - (n * t));
				int ansR = ::R[lg].get(1, 0, S, Lask - (n * t), Rask + 1 - (n * t));
				chkmax(newLn, ansL - n * t + i);
				chkmax(newRn, ansR + n * t - i);
			}	
    		if (newLn + newRn + 1 < n) {
    			ans += 1 << lg;
    			L = newLn - i, R = newRn + i;
    		}
    	}
    	cout << ans << ' ';
    }
    cout << '\n';
}