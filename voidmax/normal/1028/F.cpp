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

int n;
int alive;
map<point, int> w;
vector<int> t;
vector<point> res;
unordered_map<long long, vector<point>> who;

int gcd(int a, int b) {
    return a ? gcd(b % a, a) : b;
}

point get_point(point f) {
    auto q = gcd(f.x, f.y);
    f.x /= q;
    f.y /= q;
    return f;
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    //read("input");
    cin >> n;
    t.resize(n);
    res.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> res[i];
        if (t[i] == 3) {
            res[i] = get_point(res[i]);
            w[res[i]] = 0;
        } else {
            res[i].x <<= 1;
            res[i].y <<= 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (t[i] == 3) {
            cout << alive - w[res[i]] << '\n';
        } else {
            long long d = 1LL * res[i].x * res[i].x + 1LL * res[i].y * res[i].y;
            vector<point> cur = who[d];
            if (t[i] == 1) {
                ++alive;
                for (auto j : cur) {
                    point f = get_point({j.x + res[i].x, j.y + res[i].y});
                    if (w.count(f)) {
                        w[f] += 2;
                    }
                }
                point f = get_point(res[i]);
                if (w.count(f)) {
                    w[f] += 1;
                }
                cur.pb(res[i]);
            } else {
                --alive;
                for (int j = 0; j < cur.size(); ++j) {
                    if (cur[j] == res[i]) {
                        swap(cur[j], cur.back());
                        cur.pop_back();
                        break;
                    }
                }
                for (auto j : cur) {
                    point f = get_point({j.x + res[i].x, j.y + res[i].y});
                    if (w.count(f)) {
                        w[f] -= 2;
                    }
                }
                point f = get_point(res[i]);
                if (w.count(f)) {
                    w[f] -= 1;
                }
            }
            swap(who[d], cur);
        }
    }
}