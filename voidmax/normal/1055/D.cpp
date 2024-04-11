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

int p = 1e9 + 9, q = 1e5 + 7;

int n;
vector<string> a, b;
vector<pair<int, pair<int, int>>> arr;

void do_prime(int &p) {
	while (true) {
		bool bad = false;
		for (int i = 2; i * i <= p; ++i) {
			if (p % i == 0) {
				bad = true;
				break;
			}
		}
		if (!bad) return;
		++p;
	}
}

void solve(string L, string R) {
	vector<long long> px;
	px.pb(1);
	for (int i = 0; i < 1e5; ++i) {
		px.pb(px.back() * q % p);
	} 
	long long hsh = 0;
	for (auto i : L) {
		hsh = (hsh * q + i) % p;
	}
	// cout << "? " << hsh << endl;
	for (int i = 0; i < n; ++i) {
		vector<long long> cur_hsh;
		cur_hsh.pb(0);
		for (char c : a[i]) {
			cur_hsh.pb((cur_hsh.back() * q + c) % p);
		}
		for (int j = 0; j + L.size() <= a[i].size(); ++j) {
			long long current_hash = cur_hsh[j + L.size()] - (cur_hsh[j] * px[L.size()]);
			current_hash %= p;
			if (current_hash < 0) current_hash += p;
			if (current_hash == hsh) {
				bool OK = true;
				for (int q = 0; q < L.size(); ++q) {
					if (a[i][j + q] != L[q]) {
						OK = false;
					}
				}
				if (!OK) continue;
				for (int q = 0; q < L.size(); ++q) {
					a[i][j + q] = R[q];
				}
				break;
			}
		} 
		// cout << endl;
		// cout << a[i] << ' ' << b[i] << endl;
		if (a[i] != b[i]) {
			cout << "NO\n";
			exit(0);
		}
	}
	cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    cin >> n;
    a.resize(n);
    b.resize(n);
    cin >> a >> b;
    p -= rand() % 10000;
    q -= rand() % 100;
    do_prime(p);
    do_prime(p);
    do_prime(q);
    string badL = "", badR = "";
    for (int i = 0; i < n; ++i) {
    	int L = -1, R = -1;
    	for (int j = 0; j < a[i].size(); ++j) {
    		if (a[i][j] != b[i][j]) {
    			if (L == -1) L = j;
    			R = j;
    		}
    	}
    	if (L == -1) continue;
    	arr.pb({i, {L, R}});
    }
    while (true) {
    	bool have_left = true;
    	for (auto i : arr) {
    		if (i.y.x == 0) {
    			have_left = false;
    		}
    	}
    	if (!have_left) break; 
    	string cur;
    	for (auto i : arr) {
    		string curs = cur;
    		cur = "";
    		cur += a[i.x][i.y.x - 1];
  			cur += b[i.x][i.y.x - 1];
  			if (curs.size() && curs != cur) {
  				have_left = false;
  				break;
  			}
    	}
    	if (!have_left) break; 
    	for (auto &i : arr) {
    		--i.y.x;
    	}
    }
    while (true) {
    	bool have_left = true;
    	for (auto i : arr) {
    		if (i.y.y + 1 == a[i.x].size()) {
    			have_left = false;
    		}
    	}
    	if (!have_left) break; 
    	string cur;
    	for (auto i : arr) {
    		string curs = cur;
    		cur = "";
    		cur += a[i.x][i.y.y + 1];
  			cur += b[i.x][i.y.y + 1];
  			if (curs.size() && curs != cur) {
  				have_left = false;
  				break;
  			}
    	}
    	if (!have_left) break; 
    	for (auto &i : arr) {
    		++i.y.y;
    	}
    }
    badL = badR = "";
    for (int i = arr[0].y.x; i <= arr[0].y.y; ++i) {
    	badL += a[arr[0].x][i];
    	badR += b[arr[0].x][i];
    }
    solve(badL, badR);
    cout << badL << '\n' << badR << '\n';
}