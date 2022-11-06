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

const int N = 3.1e5;

int ans;
long long sz[N][2];
vector<int> elems[N][2];
pair<int, int> who[N];

int n, k;
vector<int> where[N];
string need;
int rep[N];

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    for (int i = 0; i < N; ++i) {
        elems[i][1] = {i};
        who[i] = {i, 1};
        sz[i][1] = 1;
    }
    cin >> n >> k >> need;
    for (int i = 0; i < k; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int v;
            cin >> v;
            --v;
            where[v].push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        rep[i] = ans;
        if (where[i].size() < 2) {
            if (where[i].empty()) continue;
            auto [id, clr] = who[where[i][0]];
            ans -= min(sz[id][0], sz[id][1]);
            if (need[i] == '0') {
                sz[id][!clr] = 1e9;
            } else {
                sz[id][clr] = 1e9;
            }
            ans += min(sz[id][0], sz[id][1]);
            rep[i] = ans;
            continue;
        }
        auto [A, clr1] = who[where[i][0]];
        auto [B, clr2] = who[where[i][1]];
        if (A == B) continue;

        ans -= min(sz[A][0], sz[A][1]);
        ans -= min(sz[B][0], sz[B][1]);

        if (elems[A][0].size() + elems[A][1].size() <
            elems[B][0].size() + elems[B][1].size()) {
            swap(A, B);
        }

        if ((need[i] != '0') ^ (clr1 == clr2)) {
            swap(elems[B][0], elems[B][1]);
            swap(sz[B][0], sz[B][1]);
        }

        for (int j : elems[B][0]) {
            who[j] = {A, 0};
            elems[A][0].push_back(j);
        }
        sz[A][0] += sz[B][0];

        for (int j : elems[B][1]) {
            who[j] = {A, 1};
            elems[A][1].push_back(j);
        }
        sz[A][1] += sz[B][1];

        elems[B][0].clear();
        elems[B][1].clear();
        elems[B][0].shrink_to_fit();
        elems[B][1].shrink_to_fit();

        ans += min(sz[A][0], sz[A][1]);
        rep[i] = ans;
    }
    for (int i = 0; i < n; ++i) {
        cout << rep[i] << '\n';
    }
}