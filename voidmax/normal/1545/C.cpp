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

const int N = 1.1e3;
const int mod = 998244353;

int n;
int p[N];
int color[N];
vector<int> edge[N];

int halfes[N];
vector<int> who;

bool dfs_end(int i, int clr) {
    if (halfes[i] && halfes[i] != clr) {
        return false;
    }
    if (halfes[i]) return true;
    halfes[i] = clr;
    who.push_back(i);
    if (clr == 2) {
        if (!dfs_end(p[i], 1)) { 
            return false;
        }
    } else {
        for (int j : edge[i]) {
            if (!dfs_end(j, 2)) { 
                return false;
            }
        }
    }
    return true;
}

void last_solve() {
    // for (int i = 0; i < n * 2; ++i) {
    //     for (int j : edge[i]) {
    //         if (i < j) {
    //             cout << i + 1 << "->" << j + 1 << endl;
    //         }
    //     }
    // }
    for (int i = 0; i < n * 2; ++i) {
        halfes[i] = 0;
        // if (color[i] == 1) {
        //     cout << i + 1 << ' ' << p[i] + 1 << '\n';
        // }
    }
    int ans = 1;
    for (int i = 0; i < n * 2; ++i) {
        if (halfes[i] || color[i] == 2) continue;
        bool L = dfs_end(i, 1);
        // cout << who.size() << '\n';
        // for (int j : who) {
        //     if (halfes[j] == 1) {
        //         cout << j + 1 << ':';
        //     }
        // }
        for (auto j : who) halfes[j] = 0;
        // cout << '\n';
        who.clear();
        bool R = dfs_end(p[i], 1);
        // cout << '\n';
        // cout << who.size() << '\n';
        // for (int j : who) {
        //     if (halfes[j] == 1) {
        //         cout << j + 1 << ':';
        //     }
        // }
        for (auto j : who) halfes[j] = 0;
        who.clear();
        // cout << "   " << L << ' ' << R << endl;
        if (L && R) {
            ans = (ans + ans) % mod;
        }
        // break;
        if (L) {
            dfs_end(i, 1); 
        } else {
            dfs_end(p[i], 1);
        }
        who.clear();
    }
    cout << ans << '\n';
    for (int i = 0; i < 2 * n; ++i) {
        if (halfes[i] == 1) {
            cout << i + 1 << ' ';
        }
    }
    cout << '\n';
}

bool used[N];
int cnt[N][N], val[N][N];
vector<pair<int, int>> order;

void del(int i, int clr) {
    if (color[i]) return;
    // cout << i + 1 << ' ' << clr << '\n';
    color[i] = clr;
    for (int j = 0; j < n; ++j) {
        if (clr == 2) {
            --cnt[j][val[i][j]];
        } else {
            cnt[j][val[i][j]] = 0;
        }
        if (cnt[j][val[i][j]] == 1) {
            order.push_back({j, val[i][j]});
        }
    }
}

bool dfs(int i) {
    if (used[i]) return false;
    used[i] = true;
    for (auto j : edge[i]) {
        if (color[i] == color[j]) continue;
        if (p[j] == -1 || dfs(p[j])) {
            p[j] = i;
            p[i] = j;
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> n;
    order.clear();
    for (int i = 0; i < 2 * n; ++i) {
        p[i] = -1;
        color[i] = 0;
        for (int j = 0; j < n; ++j) {
            cnt[i][j] = val[i][j] = 0;
        }
    }
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> val[i][j];
            --val[i][j];
            ++cnt[j][val[i][j]];
        }
    }
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < i; ++j) {
            for (int q = 0; q < n; ++q) {
                if (val[i][q] == val[j][q]) {
                    edge[i].push_back(j);
                    edge[j].push_back(i);
                    // cout << j + 1 << ' ' << i + 1 << ' ' << q + 1 << endl;
                    break;
                }
            }
        }
    }
    mt19937 rnd(228);
    for (int i = 0; i < 2 * n; ++i) {
        shuffle(edge[i].begin(), edge[i].end(), rnd);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (cnt[i][j] == 1) {
                order.push_back({i, j});
            }
        }
    }
    while (order.size()) {
        auto [col, v] = order.back();
        order.pop_back();
        if (cnt[col][v] != 1) continue;
        int id = -1;
        for (int i = 0; i < 2 * n; ++i) {
            if (!color[i] && val[i][col] == v) {
                id = i;
                break;
            }
        }
        del(id, 1);
        for (int j : edge[id]) {
            del(j, 2);
        }
    }
    for (int i = 0; i < 2 * n; ++i) {
        if (color[i]) continue;
        color[i] = cnt[0][val[i][0]]--;
    }
    for (int i = 0; i < 2 * n; ++i) {
        if (color[i] == 1) {
            for (int j = 0; j < 2 * n; ++j) {
                used[j] = false;
            }
            assert(dfs(i));
        }
    }
    last_solve();
    for (int i = 0; i < n * 2; ++i) {
        edge[i].clear();
        edge[i].shrink_to_fit();
    }
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