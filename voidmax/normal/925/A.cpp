 /*
 












 
 */
#pragma GCC optimize "-oFast"
#include <iostream>
#include <complex>
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
#include <stack>
#include <deque>
    
     
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
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define rank rank228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const string FILENAME = "input";
const int MAXN = 200228;
const int INF = 1000 * 1000 * 1000;

int n, m, cl, ce, v;
int l[MAXN], e[MAXN];
int q;


int costl(int x1, int y1, int x2, int y2, int pos) {
    pos = l[pos];
    int sum = abs(x1 - pos);
    sum += abs(y1 - y2);
    sum += abs(x2 - pos);
    return sum;
}


int coste(int x1, int y1, int x2, int y2, int pos) {
    pos = e[pos];
    int sum = abs(x1 - pos);
    sum += (abs(y1 - y2) + v - 1) / v;
    sum += abs(x2 - pos);
    return sum;
}


int checkl(int x1, int y1, int x2, int y2) {
    if (cl == 0) {
        return INF;
    }
    int f = lower_bound(l, l + cl, min(x1, x2)) - l;
    int res = INF;
    if (f < cl) {
        chkmin(res, costl(x1, y1, x2, y2, f));
    }
    f--;
    if (f >= 0) {
        chkmin(res, costl(x1, y1, x2, y2, f));
    }
    f = lower_bound(l, l + cl, max(x1, x2)) - l;
    if (f < cl) {
        chkmin(res, costl(x1, y1, x2, y2, f));
    }
    f--;
    if (f >= 0) {
        chkmin(res, costl(x1, y1, x2, y2, f));
    }
    return res;
}


int checke(int x1, int y1, int x2, int y2) {
    if (ce == 0) {
        return INF;
    }
    int f = lower_bound(e, e + ce, min(x1, x2)) - e;
    int res = INF;
    if (f < ce) {
        chkmin(res, coste(x1, y1, x2, y2, f));
    }
    f--;
    if (f >= 0) {
        chkmin(res, coste(x1, y1, x2, y2, f));
    }
    f = lower_bound(e, e + ce, max(x1, x2)) - e;
    if (f < ce) {
        chkmin(res, coste(x1, y1, x2, y2, f));
    }
    f--;
    if (f >= 0) {
        chkmin(res, coste(x1, y1, x2, y2, f));
    }
    return res;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //read(FILENAME);
    cin >> n >> m >> cl >> ce >> v;
    for (int i = 0; i < cl; i++) {
        cin >> l[i];
    }
    sort(l, l + cl);
    for (int i = 0; i < ce; i++) {
        cin >> e[i];
    }
    sort(e, e + ce);
    cin >> q;
    for (int it = 0; it < q; it++) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        if (y1 == y2) {
            cout << abs(x1 - x2) << '\n';
            continue;
        }
        int f = checkl(x1, y1, x2, y2);
        chkmin(f, checke(x1, y1, x2, y2));
        cout << f << '\n';
    }
    return 0;
}