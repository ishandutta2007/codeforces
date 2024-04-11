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
 
typedef long long base;        
typedef pair<base, base> point;

const int N = 5e5 + 100;

int n, m, k;
long long ans;

struct my_dsu {
    int s[N], dsu[N];

    my_dsu() {
        for (int i = 0; i < N; ++i) {
            s[i] = 1;
            dsu[i] = i;
        }
    }

    int get(int i) {
        if (dsu[i] == i) return i;
        return dsu[i] = get(dsu[i]);
    }

    bool merge(int i, int j) {
        i = get(i), j = get(j);
        if (i == j) return false;
        if (s[i] < s[j]) swap(i, j);
        s[i] += s[j];
        dsu[j] = i;
        return true;
    }
} res[2];

int L[N], R[N];
int a[N], b[N], c[N];

vector<pair<bool, int>> edge[N];

pair<bool, int> up[N];
int h[N];
int who[N];

int get(int i) {
    if (who[i] == i) return i;
    return who[i] = get(who[i]);
}

bool used[N];

void dfs(int i) {
    if (used[i]) return;
    who[i] = i;
    used[i] = true;
    for (auto j : edge[i]) {
        if (used[j.y]) continue;
        h[j.y] = h[i] + 1;
        up[j.y] = {j.x, i};
        dfs(j.y);
    }
}

vector<int> lb;

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    //read("input");
    cin >> n >> k >> m;
    for (int i = 0; i < k; ++i) {
        cin >> L[i] >> R[i];
        res[0].merge(L[i], R[i]);
        edge[L[i]].pb({1, R[i]});
        edge[R[i]].pb({1, L[i]});
    }
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        if (res[0].get(a[i]) == res[0].get(b[i]) &&
                res[1].get(a[i]) != res[1].get(b[i])) {
            lb.pb(i);
        } else {
            res[0].merge(a[i], b[i]);
            res[1].merge(a[i], b[i]);
            edge[a[i]].pb({0, b[i]});
            edge[b[i]].pb({0, a[i]});
        }
    }
    for (int i = 0; i < n; ++i) {
        dfs(i);
    }
    int cnt = 0;
    for (auto i : lb) {
        int L = get(a[i]), R = get(b[i]);
        // cout << L << ' ' << R << endl;
        vector<int> chg;
        while (L != R) {
            chg.pb(L);
            chg.pb(R);
            if (h[L] < h[R]) swap(L, R);
            if (up[L].x) {
                ++cnt;
                up[L].x = 0;
                ans += c[i];
            } 
            L = get(up[L].y);
        }
        for (auto j : chg) who[j] = L;
    }
    if (cnt != k) ans = -1;
    cout << ans << '\n';
    
}