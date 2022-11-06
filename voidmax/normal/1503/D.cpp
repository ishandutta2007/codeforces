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
#include <numeric>
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

const int N = 4e5 + 5;

int n;
int L[N], R[N], LN[N], RN[N];
int dsu[N];

int get(int i) {
    return i == dsu[i] ? i : (dsu[i] = get(dsu[i]));
}

void merging(int i, int j) {
    if (get(i) != get(j)) {
        dsu[get(i)] = get(j);
    }
}

struct fen {
    int minval[N];
    vector<int> a[N];

    fen() {
        for (int i = 0; i < N; ++i) {
            minval[i] = 2e9;
        }
    }

    void add(int i, int id) {
        while (i < N) {
            chkmin(minval[i], RN[id]);
            a[i].push_back(id);
            i |= (i + 1);
        }
    }

    pair<int, int> get(int i) {
        int lst = -1;
        int minv = 2e9;
        while (i >= 0) {
            if (a[i].size()) {
                chkmin(minv, minval[i]);
                while (a[i].size() > 1) {
                    merging(a[i].back(), a[i][0]);
                    a[i].pop_back();
                }
                if (lst == -1) {
                    lst = a[i][0];
                } else {
                    merging(a[i][0], lst);
                    lst = ::get(lst);
                }
            }
            i &= (i + 1);
            --i;
        }
        return {lst, minv};
    }
} box;

vector<int> order;
vector<int> who[N];
vector<int> edge[N];
int clr[N];

vector<int> half[2];

void dfs(int i, int cur = 1) {
    if (clr[i] && clr[i] != cur) {
        cout << -1 << '\n';
        exit(0);
    }
    if (clr[i]) return;
    clr[i] = cur;
    for (int j : who[i]) {
        half[clr[i] - 1].push_back(j);
    }
    for (auto j : edge[i]) {
        dfs(j, 3 - cur);
    }
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    cin >> n;
    order.resize(n);
    iota(order.begin(), order.end(), 0);
    iota(dsu, dsu + n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> L[i] >> R[i];
        LN[i] = min(L[i], R[i]);
        RN[i] = max(L[i], R[i]);
    }
    sort(order.begin(), order.end(), [&](int i, int j) {
        return LN[i] < LN[j];
    });
    vector<pair<int, int>> interest;
    for (int i : order) {
        auto [lst, minv] = box.get(RN[i]);
        if (lst != -1) interest.push_back({lst, i});
        if (minv < LN[i]) {
            cout << -1 << '\n';
            return 0;
        }
        box.add(RN[i], i);
    }
    for (int i = 0; i < n; ++i) {
        who[get(i)].push_back(i);
    }
    for (auto [a, b] : interest) {
        a = get(a);
        b = get(b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (clr[i]) continue;
        dfs(i);
        int cnt = 0;
        for (int j : half[0]) {
            // cout << L[j] << ':' << R[j] << ' ';
            if (L[j] != LN[j]) {
                ++cnt;
            }
        }
        // cout << "= ";
        for (int j : half[1]) {
            // cout << L[j] << ':' << R[j] << ' ';
            if (L[j] != RN[j]) {
                ++cnt;
            }
        }
        // cout << '\n';
        cnt = min(cnt, int(half[0].size() + half[1].size()) - cnt);
        ans += cnt;
        half[0].clear();
        half[1].clear();
    }
    cout << ans << '\n';
}