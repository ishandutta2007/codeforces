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
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
// #pragma GCC optimize("unroll-loops")    
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
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
typedef pair<base, base> point;

int s, f; 
int p = 1e9 + 7;

int sum(int a, int b) {
	a += b;
	return a < p ? a : a - p;
}

int mul(long long a, int b) {
	return a * b % p;
}

int powx(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = mul(ans, a);
		a = mul(a, a);
		b >>= 1;
	}
	return ans;
}

queue<int> que[4];
unordered_map<int, int> dist[2];
unordered_map<int, point> way[2];

vector<int> get(int v, int t, int d = -1) {
	if (d == -1) d = dist[t][v];
	if (d == 0) return {};
	auto ans = get(way[t][v].y, t, d - 1);
	ans.pb(way[t][v].x);
	return ans;
}

int main() {
    ios::sync_with_stdio(false);
    srand(time(0));
    cin >> s >> f >> p;
    int ans = p;
    int res = -1;
    que[0].push(s);
    que[1].push(f);
    dist[0][s] = 0;
    dist[1][f] = 0;
    int d = 0;
   	while (res == -1) {
   		for (int t = 0; t < 2; ++t) {
   			while (que[t].size()) {
   				auto u = que[t].front();
   				que[t].pop();
   				int v = sum(u, 1);
   				if (!dist[t].count(v)) {
   					dist[t][v] = d + 1;
   					if (dist[!t].count(v)) {
   						chkmin(ans, dist[!t][v] + d + 1);
   						res = v;
   					}
   					way[t][v] = {1, u};
   					que[t + 2].push(v);
   				}
   				v = sum(u, p - 1);
   				if (!dist[t].count(v)) {
   					dist[t][v] = d + 1;
   					if (dist[!t].count(v)) {
   						chkmin(ans, dist[!t][v] + d + 1);
   						res = v;
   					}
   					way[t][v] = {2, u};
   					que[t + 2].push(v);
   				}
   				v = powx(u, p - 2);
   				if (!dist[t].count(v)) {
   					dist[t][v] = d + 1;
   					if (dist[!t].count(v)) {
   						chkmin(ans, dist[!t][v] + d + 1);
   						res = v;
   					}
   					way[t][v] = {3, u};
   					que[t + 2].push(v);
   				}
   			}
   			swap(que[t], que[t + 2]);
   		}
   		++d;
   	}
   	vector<int> L = get(res, 0);
   	vector<int> R = get(res, 1);
   	reverse(R.begin(), R.end());
   	cout << L.size() + R.size() << endl;
   	for (int i = 0; i < R.size(); ++i) {
   		if (R[i] != 3) R[i] = 3 - R[i];
   	}
   	if (L.size()) {
   		cout << L << ' ' << R << endl;
   	} else {
   		cout << R << endl;
   	}
}