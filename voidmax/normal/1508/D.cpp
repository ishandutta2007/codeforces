#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("unroll-loops")    
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
#include <random>
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

point operator - (point a, point b) { 
    return {a.x - b.x, a.y - b.y};
}

long long operator * (point a, point b) {
    return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

const int N = 2e3 + 5;

int n;
int a[N];
point p[N];
vector<int> bad;


int dsu[N];

int get(int i) {
    return dsu[i] == i ? i : (dsu[i] = get(dsu[i]));
}


int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> a[i];
        --a[i];
        if (i != a[i]) {
            bad.push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        dsu[i] = i;
    }
    point o = {2e9, 2e9};
    for (int i : bad) {
        o = min(o, p[i]);
        if (get(i) != get(a[i])) {
            dsu[get(i)] = get(a[i]);
        }
    }
    vector<pair<int, int>> ans;
    vector<int> rest;
    int id = 0;
    for (int i : bad) {
        if (o != p[i]) {
            rest.push_back(i);
        } else {
            id = i;
        }
    }
    sort(rest.begin(), rest.end(), [&](int i, int j) {
        return (p[i] - o) * (p[j] - o) < 0;
    });
    for (int i = 1; i < rest.size(); ++i) {
        if (get(rest[i - 1]) != get(rest[i])) {
            ans.emplace_back(rest[i - 1], rest[i]);
            swap(a[rest[i - 1]], a[rest[i]]);
            dsu[get(rest[i - 1])] = get(rest[i]);
        }
    }
    while (a[id] != id) {
        ans.push_back({id, a[id]});
        swap(a[id], a[a[id]]);
    }
    cout << ans.size() << '\n';
    for (auto [L, R] : ans) {
        cout << L + 1 << ' ' << R + 1 << '\n';
    }
}