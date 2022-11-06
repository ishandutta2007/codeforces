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
#include <bits/stdc++.h>
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
long long s, b, k, h;
int dist[101][101];
vector<int> a[1001];
vector<int> edge[2001];

int cnt = 1;
int p[2001];
int used[2001];

bool dfs(int i) {
    if (used[i] == cnt) return false;
    used[i] = cnt;
    for (auto j : edge[i]) {
        if (!p[j] || dfs(p[j])) {
            p[j] = i;
            p[i] = j;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dist[i][j] = 1e9 + 7;
        }
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        chkmin(dist[a][b], 1);
        chkmin(dist[b][a], 1);
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                chkmin(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    cin >> s >> b >> k >> h;
    for (int i = 1; i <= s; ++i) {
        a[i].resize(3);
        cin >> a[i];
    }
    for (int i = 1; i <= b; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        for (int j = 1; j <= s; ++j) {
            if (dist[v1][a[j][0]] <= a[j][2] && v2 <= a[j][1]) {
                edge[j].pb(i + s);
            }
        }
    }
    for (int i = 1; i <= s; ++i) random_shuffle(edge[i].begin(), edge[i].end());
    bool chg = true;
    while (chg) {
        chg = false;
        ++cnt;
        for (int i = 1; i <= s; ++i) {
            if (p[i]) continue;
            chg |= dfs(i);
        }
    }
    int can = 0;
    for (int i = 1; i <= s; ++i) can += (p[i] == 0);
    long long ans = 4e18;
    chkmin(ans, k * (s - can));
    chkmin(ans, h * s);
    cout << ans << endl;
}