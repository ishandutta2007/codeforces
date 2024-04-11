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

const int N = 2e5 + 5;
const int T = 1 << 18;




int n, m;
vector<vector<int>> edges;
set<int> edge[N];

vector<int> cur;
set<int> unused;

void dfs(int i) {
    unused.erase(i);
    cur.push_back(i);
    int L = 0;
    for (auto R : edge[i]) {
        while (true) {
            auto it = unused.lower_bound(L);
            if (it == unused.end() || *it >= R) {
                break;
            }
            dfs(*it);
        }
        L = R + 1;
    }
}


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
    cin >> n >> m; 
    int x = 0;
    for (int i = 0; i < n; ++i) {
        edge[i].insert(n);
    }
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        edge[a].insert(b);
        edge[b].insert(a);
        edges.push_back({w, a, b});
        x ^= w;
    }
    if (1LL * n * (n - 1) / 2 - m <= n) {
        vector<pair<int, int>> interest;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (edge[i].count(j) == 0) {
                    interest.emplace_back(i, j);
                }
            }
        }

        pair<int, int> bad = {-1, -1};
        for (int i = 0; i < n; ++i) {
            dsu[i] = i;
        }
        for (auto [a, b] : interest) {
            if (get(a) == get(b)) {
                bad = {a, b};
                break;
            }
            dsu[get(a)] = get(b);
        }

        if (bad.x == -1) {
            vector<vector<int>> cool;
            sort(edges.begin(), edges.end());
            for (int i = 0; i < n; ++i) {
                dsu[i] = i;
            }
            for (auto [a, b] : interest) {
                if (get(a) != get(b)) {
                    dsu[get(a)] = get(b);
                }
            }
            for (auto v : edges) {
                if (get(v[1]) != get(v[2])) {
                    dsu[get(v[1])] = get(v[2]);
                    cool.push_back(v);
                }
            }

            for (int i = 0; i < n; ++i) {
                dsu[i] = i;
            }
            for (auto v : cool) {
                dsu[get(v[1])] = get(v[2]);
            }
            for (auto v : edges) {
                if (get(v[1]) != get(v[2])) {
                    dsu[get(v[1])] = get(v[2]);
                    cool.push_back(v);
                    break;
                }
            }
            for (auto [a, b] : interest) {
                if (get(a) == get(b)) {
                    bad = {a, b};
                    break;
                }
                dsu[get(a)] = get(b);
            }
        }
        if (bad.x == -1) {
            bad = interest[0];
        }
        for (auto [a, b] : interest) {
            if (make_pair(a, b) == bad) {
                edges.push_back({x, a, b});
            } else {
                edges.push_back({0, a, b});
            }
        }
        for (int i = 0; i < n; ++i) {
            dsu[i] = i;
        }
    } else {
        for (int i = 0; i < n; ++i) {
            dsu[i] = i;
            unused.insert(i);
        }
        for (int i = 0; i < n; ++i) {
            if (unused.count(i)) {
                dfs(i);
                for (auto i : cur) {
                    dsu[i] = cur[0];
                }
                cur.clear();
            }
        }    
    }
    long long ans = 0;
    sort(edges.begin(), edges.end());
    for (auto v : edges) {
        if (get(v[1]) != get(v[2])) {
            dsu[get(v[1])] = get(v[2]);
            ans += v[0];
        }
    }
    cout << ans << '\n';
}