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
#include <numeric>
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

const int N = 1e6 + 5;

int n, m;
long long L[N], R[N];

void solve() {
    set<pair<long long, int>> Rseg;
    vector<pair<long long, int>> events;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        events.push_back({a, -1});
    }
    events.push_back({4e9, -1});
    for (int i = 0; i < m; ++i) {
        cin >> L[i] >> R[i];
        events.push_back({L[i], i});
    }
    long long lst = -4e9;
    sort(events.begin(), events.end());
    long long dp0 = 0, dp1 = 0;
    for (auto ev : events) {
        auto [_c, tp] = ev;
        long long c = _c;
        if (tp != -1) {
            while (Rseg.size() && Rseg.rbegin()->first >= R[tp]) {
                int id = Rseg.rbegin()->second;
                Rseg.erase(*Rseg.rbegin());
            } 
            Rseg.insert({R[tp], tp});
        } else {
            while (Rseg.size() && Rseg.rbegin()->first >= c) {
                Rseg.erase(*Rseg.rbegin());
            } 
            if (Rseg.size()) {
                long long ndp0 = 1e18, ndp1 = 1e18;
                vector<long long> LL, RR;
                // cout << "? " << lst << ' ' << c << '\n';
                for (auto [coor, id] : Rseg) {
                    LL.push_back(L[id]);
                    RR.push_back(R[id]);
                    // cout << L[id] << ' ' << R[id] << '\n';
                }
                chkmin(ndp0, min(dp0, dp1) + (c - RR[0]) * 2);
                chkmin(ndp1, min(dp0, dp1) + (c - RR[0]));
                chkmin(ndp0, dp0 + (LL.back() - lst));
                chkmin(ndp0, dp1 + (LL.back() - lst) * 2);
                for (int i = 0; i + 1 < LL.size(); ++i) {
                    long long dpL = min(dp0 + (LL[i] - lst), dp1 + (LL[i] - lst) * 2);
                    chkmin(ndp0, dpL + (c - RR[i + 1]) * 2);
                    chkmin(ndp1, dpL + (c - RR[i + 1]));
                }
                dp0 = ndp0;
                dp1 = min(ndp1, ndp0);
                // cout << "dp " << dp0 << ' ' << dp1 << '\n';
                // cout << '\n';
            } else {
                dp0 = dp1;
            }
            Rseg.clear();
            lst = c;
        }
    }
    cout << min(dp0, dp1) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}