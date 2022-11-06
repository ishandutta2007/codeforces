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
#define tm _tm
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

int n, m, q;
map<pair<int, int>, vector<int>> tm; 
vector<vector<int>> query;


int cnt;
int L[N], R[N], w[N], a[N], b[N];
int ord[N];

int it;
// vector<long long> res;

long long cur_ans = 1e18;
vector<vector<int>> chg;
vector<int> edge[N];
vector<vector<int>> edges;

void solve(int Ln, int Rn) {
    long long was_ans = cur_ans;
    int was_cnt = cnt;
    int was_chg = chg.size();
    auto was_edges = edges;
    // cout << "\t" << Ln << ' ' << Rn << '\n';
    for (int j = 0; j < cnt; ++j) {
        int i = ord[j];
        if (L[i] <= Ln && Rn <= R[i]) {
            for (int q = 0; q < edges.size(); ++q) {
                if (edges[q][1] == a[i] || edges[q][1] == b[i]) continue;
                if (edges[q][2] == a[i] || edges[q][2] == b[i]) continue;
                chkmin(cur_ans, 1LL * w[i] + edges[q][0]);
            }
            // cout << "+ " << a[i] + 1 << ' ' << b[i] + 1 << ' ' << w[i] << ' ' << L[i] << ' ' << R[i] << '\n';
            for (int t = 0; t < 2; ++t) {
                chg.push_back(edge[a[i]]);
                chg.back().push_back(a[i]);
                edge[a[i]].push_back(w[i]);
                sort(edge[a[i]].begin(), edge[a[i]].end());
                if (edge[a[i]].size() == 4) {
                    edge[a[i]].pop_back();
                }
                if (edge[a[i]].size() == 3) {
                    chkmin(cur_ans, 1LL * edge[a[i]][0] + edge[a[i]][1] + edge[a[i]][2]);
                }
                swap(a[i], b[i]);
            }
            // cout << "USED " << res.back().size() << '\n';
            edges.push_back({w[i], a[i], b[i]});
            sort(edges.begin(), edges.end());
            unordered_map<int, char> used;
            for (int q = 0; q < edges.size(); ++q) {
                int u = edges[q][1];
                int v = edges[q][2];
                ++used[u], ++used[v];
                if (used[u] > 3 || used[v] > 3) {
                    edges.erase(edges.begin() + q);
                    break;
                }
            }
            if (edges.size() >= 6) {
                edges.pop_back();
            }
            swap(ord[--cnt], ord[j--]);
        } else if (Rn <= L[i] || R[i] <= Ln) {
            swap(ord[--cnt], ord[j--]);
        } 
    }
    if (Rn - Ln == 1) {
        assert(cnt == 0);
        cout << cur_ans << '\n';
    } else {
        int M = (Ln + Rn) >> 1;
        solve(Ln, M);
        solve(M, Rn);
    }
    cnt = was_cnt;
    while (chg.size() != was_chg) {
        int a = chg.back().back();
        chg.back().pop_back();
        edge[a] = chg.back();
        chg.pop_back();
    }
    edges = was_edges;
    cur_ans = was_ans;
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        tm[{min(a, b), max(a, b)}].push_back(i);
        query.push_back({a, b, w});   
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int t, a, b, w;
        cin >> t >> a >> b;
        if (t) cin >> w;
        --a, --b;
        tm[{min(a, b), max(a, b)}].push_back(i + m);
        query.push_back({a, b, w});  
    }
    for (auto [ab, v] : tm) {
        auto [a, b] = ab;
        if (v.size() & 1) {
            v.push_back(m + q + 1);
        }
        for (int i = 0; i < v.size(); i += 2) {
            ord[cnt] = cnt;
            L[cnt] = v[i];
            R[cnt] = v[i + 1];
            w[cnt] = query[v[i]][2];
            ::a[cnt] = a;
            ::b[cnt] = b;
            // cout << a + 1 << ' ' << b + 1 << ' ' << w[cnt] << ' ' << L[cnt] << ' ' << R[cnt] << '\n';
            ++cnt;
        }
    }
    solve(m - 1, m + q);
}