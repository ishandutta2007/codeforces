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

int n;
int cnt[101];
int ans = 1;

const int p[2] = {1000000007, 1000000009};

int cnk[2][101][101];
int can[2][101][10001];

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    cin >> n;
    set<int> v;
    for (int i = 0; i < n; ++i) {
    	int a;
    	cin >> a;
    	v.insert(a);
    	cnt[a]++;
    }
    if (v.size() <= 2) {
    	cout << n << endl;
    	return 0;
    } 
    ans = 1;
    for (int t = 0; t < 2; ++t) {
	    for (int i = 0; i <= 100; ++i) {
	    	cnk[t][i][i] = cnk[t][i][0] = 1;
	    	for (int j = 1; j < i; ++j) {
	    		cnk[t][i][j] = cnk[t][i - 1][j - 1] + cnk[t][i - 1][j];
	    		if (cnk[t][i][j] >= p[t]) cnk[t][i][j] -= p[t];
	    	}
	    }
	    can[t][0][0] = 1;
   		for (int w = 1; w <= 100; ++w) {
   			for (int j = 0; j < cnt[w]; ++j) {
   				for (int tx = n; tx--;) {
	   				for (int q = 10000 - w; q >= 0; --q) {
	   					can[t][tx + 1][q + w] += can[t][tx][q];
	   					if (can[t][tx + 1][q + w] >= p[t]) {
	   						can[t][tx + 1][q + w] -= p[t];
	   					}
	   				}
	   			}
   			}
   		}
   	}
   	// for (int i = 0; i < 10; ++i) {
   	// 	cout << i << ":";
   	// 	for (int j = 0; j < 4; ++j) {
   	// 		cout << can[0][j][i] << ' ';
   	// 	}
   	// 	cout << endl;
   	// }
   	// cout << cnk[2][2] << 
   	// cout << can[0][2][4] << endl;
    for (int i = 1; i <= 100; ++i) {
    	for (int j = 2; j <= cnt[i]; ++j) {
    		if (can[0][j][j * i] == cnk[0][cnt[i]][j] &&
    			can[1][j][j * i] == cnk[1][cnt[i]][j]) {
    			chkmax(ans, j);
    		}
	   	}
    }
    cout << ans << endl;
}