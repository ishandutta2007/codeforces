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

const int N = 4e5 + 5;

int n, m;
vector<int> who[N];
vector<int> edge[3][N];
vector<int> top_sort;
int a[N];

int get_id(int x, int y) {
    return y * m + x;
}

void add_edge(int a, int b) {
    // cout << a / m + 1 << ' ' << a % m + 1 << " --> ";
    // cout << b / m + 1 << ' ' << b % m + 1 << "\n";
    edge[0][a].push_back(b);
    edge[1][b].push_back(a);
}

int used[N];

void dfs(int i) {
    if (used[i]) return;
    used[i] = true;
    for (auto j : edge[1][i]) {
        dfs(j);
    }
    top_sort.push_back(i);
}

int cnt = 1;
int clr[N];

void dfs2(int i) {
    if (clr[i]) return;
    clr[i] = cnt;
    for (auto j : edge[0][i]) {
        dfs2(j);
    }
}

void dfs3(int i) {
    if (used[i] >= 2) return;
    used[i] = max(used[i], 2);
    for (int j : edge[2][i]) {
        dfs3(j);
    }
}

int L[N], R[N];

void dfs4(int i) {
    if (used[i]) return;
    used[i] = true;
    for (int j : edge[2][i]) {
        dfs4(j);
        chkmin(L[i], L[j]);
        chkmax(R[i], R[j]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '#') {
                who[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int jj = 0; jj < who[i].size(); ++jj) {
            int j = who[i][jj];
            if (jj && who[i][jj - 1] == j - 1) {
                add_edge(get_id(i, j), get_id(i, j - 1));
            }
            if (jj + 1 < who[i].size()) {
                add_edge(get_id(i, j), get_id(i, who[i][jj + 1]));
            }
            if (i) {
                auto it = lower_bound(who[i - 1].begin(), who[i - 1].end(), j);
                if (it != who[i - 1].end()) {
                    add_edge(get_id(i, j), get_id(i - 1, *it));
                }
            }
            if (i + 1 < m) {
                auto it = lower_bound(who[i + 1].begin(), who[i + 1].end(), j);
                if (it != who[i + 1].end()) {
                    add_edge(get_id(i, j), get_id(i + 1, *it));
                }
            }
        }
    }
    for (int i = 0; i < n * m; ++i) {
        dfs(i);
    }
    reverse(top_sort.begin(), top_sort.end());
    for (int i : top_sort) {
        if (!clr[i]) {
            dfs2(i);
            ++cnt;
        }
    }
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << clr[get_id(j, i)];
    //     }
    //     cout << '\n';
    // }
    for (int i = 0; i < n * m; ++i) {
        for (int j : edge[0][i]) {
            edge[2][clr[i]].push_back(clr[j]);
        }
    }
    memset(used, 0, sizeof(used));
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        if (a[i] == 0) continue;
        int id = clr[get_id(i, who[i][who[i].size() - a[i]])];
        if (used[id]) continue;
        dfs3(id);
        used[id]--;
    }
    int cool = 0;
    for (int i = 0; i < cnt; ++i) {
        L[i] = n + 1;
        R[i] = -1;
    }
    for (int i = 0; i < m; ++i) {
        if (a[i] == 0) continue;
        int id = clr[get_id(i, who[i][who[i].size() - a[i]])];
        if (used[id] > 1) continue;
        L[id] = R[id] = cool;
        // cout << id << "!" << endl;
        ++cool;
        ++used[id];
    }
    cout << cool << endl;
    return 0;
    // for (int i = 0; i < cnt; ++i) {
    //     for (int j : edge[2][i]) {
    //         if (i != j) {
    //             cout << i + 1 << ' ' << j + 1 << '\n';
    //         }
    //     }
    // }
    memset(used, 0, sizeof(used));
    vector<pair<int, int>> segments;
    for (int i = 0; i < cnt; ++i) {
        dfs4(i);
        if (L[i] <= R[i]) {
            // cout << i << ": "<< L[i] + 1 << ' ' << R[i] + 1 << '\n';
            segments.push_back({L[i], R[i]});
        }
    }
    sort(segments.begin(), segments.end());
    int lst = 0, cur = 0;
    int maxR = -1;
    int ans = 0;
    while (lst != cool) {
        while (cur < segments.size() && segments[cur].first <= lst) {
            maxR = max(maxR, segments[cur].second);
            ++cur;
        }
        lst = maxR + 1;
        ++ans;
    }
    cout << ans << '\n';
}