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
typedef pair<base, base> point;

const int N = 2e5 + 2;

int n, q;
int L[N], R[N];
int clr[N];
int mclr[N];
set<int> cool;

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    //read("input");
    cin >> n >> q;
    for (int i = 0; i <= q; ++i) {
        L[i] = 1e9;
        R[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> clr[i];
        cool.insert(i);
        chkmin(L[clr[i]], i);
        chkmax(R[clr[i]], i);
    }
    for (int i = q; i > 0; --i) {
        while (cool.size()) {
            auto it = cool.lower_bound(L[i]);
            if (it == cool.end() || *it > R[i]) 
                break;
            mclr[*it] = i;
            cool.erase(it);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (clr[i] != 0 && clr[i] != mclr[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (L[q] == 1e9) {
        bool found = false;
        for (int i = 0; i < n; ++i) {
            if (clr[i] == 0) {
                found = true;
                mclr[i] = q;
                break;
            }
        }
        if (!found) {
            cout << "NO" << endl;
            return 0;
        }
    }
    for (int i = 1; i < n; ++i) {
        if (mclr[i] == 0) {
            mclr[i] = mclr[i - 1];
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        if (mclr[i] == 0) {
            mclr[i] = mclr[i + 1];
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cout << mclr[i] << ' ';
    }
    cout << endl;
}