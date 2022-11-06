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

const int N = 2e5;

int n;
int pref[N][4], suf[N][4];

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    //read("input");
    cin >> n;
    pref[0][0] = suf[n + 1][0] = -1e9;
    pref[0][1] = suf[n + 1][1] = -1e9;
    pref[0][2] = suf[n + 1][2] = 1e9;
    pref[0][3] = suf[n + 1][3] = 1e9;
    for (int i = 1; i <= n; ++i) {
        point a, b;
        cin >> a >> b;
        pref[i][0] = suf[i][0] = a.x;
        pref[i][1] = suf[i][1] = a.y;
        pref[i][2] = suf[i][2] = b.x;
        pref[i][3] = suf[i][3] = b.y;
    }
    for (int i = 1; i <= n; ++i) {
        chkmax(pref[i][0], pref[i - 1][0]);
        chkmax(pref[i][1], pref[i - 1][1]);
        chkmin(pref[i][2], pref[i - 1][2]);
        chkmin(pref[i][3], pref[i - 1][3]);
    }
    for (int i = n; i >= 1; --i) {
        chkmax(suf[i][0], suf[i + 1][0]);
        chkmax(suf[i][1], suf[i + 1][1]);
        chkmin(suf[i][2], suf[i + 1][2]);
        chkmin(suf[i][3], suf[i + 1][3]);
    }
    for (int i = 1; i <= n; ++i) {
        int Lx = -1e9, Ly = -1e9, Rx = 1e9, Ry = 1e9;
        chkmax(Lx, suf[i + 1][0]);
        chkmax(Ly, suf[i + 1][1]);
        chkmin(Rx, suf[i + 1][2]);
        chkmin(Ry, suf[i + 1][3]);
        chkmax(Lx, pref[i - 1][0]);
        chkmax(Ly, pref[i - 1][1]);
        chkmin(Rx, pref[i - 1][2]);
        chkmin(Ry, pref[i - 1][3]);
        if (Lx <= Rx && Ly <= Ry) {
            cout << Lx << ' ' << Ly << '\n';
            return 0;
        }
    }
}