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

const int N = 1e5 + 5;

int n;
vector<int> edge[N];
unordered_map<int, int> dp[N];
vector<pair<int, int>> res[N];

int dfs(int i, int p);

void calc_all(int i) {
    if (res[i].size()) {
        return;
    }
    for (int j : edge[i]) {
        res[i].push_back({dfs(j, i), j});
    }
    sort(res[i].rbegin(), res[i].rend());
    vector<int> maxL(1, 0);
    int cur = 0;
    for (int j = 0; j < res[i].size(); ++j) {
        chkmax(cur, max(1, res[i][j].first) + j);
        maxL.push_back(cur);
    }
    int maxR = 0;
    // cout << i << endl;
    //     cout << res[i] << endl;
    //     cout << maxL << endl;
    // cout << "---\n";
    for (int j = res[i].size(); j--;) {
        dp[i][res[i][j].second] = max(max(maxR, maxL[j]), (int)edge[i].size() - 1);
        maxR = max(maxR, max(1, res[i][j].first) + j - 1);
    }
}

int dfs(int i, int p = -1) {
    if (dp[i].count(p)) {
        return dp[i][p];
    }
    if (dp[i].size()) {
        calc_all(i);
        return dp[i][p];
    } 
    vector<int> cur;
    for (int j : edge[i]) {
        if (p == j) continue;
        cur.push_back(dfs(j, i));
    }
    sort(cur.rbegin(), cur.rend());
    int ans = (int)cur.size();
    for (int j = 0; j < cur.size(); ++j) {
        cur[j] += j;
        chkmax(ans, cur[j]);
    }
    return dp[i][p] = ans;
}

vector<int> rep;

int solve(int i, int p = -1) {
    int asked = 0, cnt = 1 + int(p == -1);
    for (auto [val, j] : res[i]) {
        if (j == p) continue;
        int ans = solve(j, i);
        if (ans < 0) {
            ans = -ans;
            if (ans != i) {
                return -ans;
            } 
        } else {
            --cnt;
            if (cnt == 0) {
                return ans;
            }
        }
        asked++;
    }
    if (!asked) {
        cout << "? " << i << endl;
        int ans;
        cin >> ans;
        if (ans != i) {
            return -ans;
        }
        rep.push_back(ans);
        return ans;
    } else {
        rep.push_back(i);
        return i;
    }
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        cout << "! 1 1" << endl;
        return 0;
    }
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        // for (int j : edge[i]) {
        //     cout << i << ' ' << j << ' ' << dfs(j, i) << '\n';
        // }
        calc_all(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int maxL = res[i][0].first;
        for (int j = 1; j < res[i].size(); ++j) {
            chkmax(ans, max(maxL, 1) + res[i][j].first + j - 1);
            chkmax(maxL, res[i][j].first);
        }
        chkmax(ans, max(maxL, 1) + res[i].size() - 1);
    }
    cout << ans << endl;
    int f;
    cin >> f;
    solve(f, -1);
    if (rep.size() == 1) rep.push_back(f);
    cout << "! ";
    for (auto i : rep) {
        cout << i << ' ';
    }
    cout << endl;
}