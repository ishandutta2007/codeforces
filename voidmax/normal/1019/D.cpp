
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
   
typedef long double base;        
typedef pair<long long, long long> point;

point operator - (point a, point b) {
    return {a.x - b.x, a.y - b.y};
}

long long operator * (point a, point b) {
    return a.x * b.y - a.y * b.x;
}

base len(point a) {
    return hypot(a.x, a.y);
}

int n;
long long s;
vector<point> a;
  
long double dist(point a, point b, point c) {
    long double s = (a - b) * (c - b);
    return s / len(a - b);
}

int p[2001];
vector<int> ord;

bool cmp(point i, point j) {
    return (a[i.y] - a[i.x]) * (a[j.y] - a[j.x]) < 0;
}

vector<point> que;
point cent;

bool cmp_first(int i, int j) {
    return dist(a[cent.x], a[cent.y], a[i]) < dist(a[cent.x], a[cent.y], a[j]);
}

void find(point A, point B, long long s) {
    int L = -1, R = ord.size();
    while (R - L > 1) {
        int M = (L + R) >> 1;
        point C = a[ord[M]];
        long long curs = (A - B) * (C - B);
        if (curs == s) {
            cout << "Yes\n";
            cout << A << '\n' << B << '\n' << C << '\n';
            exit(0);
        }
        if (curs < s) {
            L = M;
        } else {
            R = M;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    //read("input");
    cin >> n >> s;
    s <<= 1;
    a.resize(n);
    cin >> a;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        ord.pb(i);
        for (int j = i + 1; j < n; ++j) {
            que.pb({i, j});
        }
    }
    sort(que.begin(), que.end(), cmp);
    cent = que[0];
    sort(ord.begin(), ord.end(), cmp_first);
    for (int i = 0; i < n; ++i) {
        p[ord[i]] = i;
    }
    for (int i = 0; i < que.size(); ++i) {
        auto c = que[i];
        find(a[c.x], a[c.y], s);
        find(a[c.x], a[c.y], -s);
        if (i + 1 == que.size()) break;
        auto d = que[i + 1];
        if (p[c.x] < p[c.y]) {
            swap(p[c.x], p[c.y]);
            swap(ord[p[c.x]], ord[p[c.y]]);
        }
    }
    cout << "No\n";
}