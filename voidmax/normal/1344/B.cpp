//                               __...------------._
//                            ,-'                   `-.
//                         ,-'                         `.
//                       ,'                            ,-`.
//                      ;                              `-' `.
//                     ;                                 .-. \
//                    ;                           .-.    `-'  \
//                   ;                            `-'          \
//                  ;                                          `.
//                  ;                                           :
//                 ;                                            |
//                ;                                             ;
//               ;                            ___              ;
//              ;                        ,-;-','.`.__          |
//          _..;                      ,-' ;`,'.`,'.--`.        |
//         ///;           ,-'   `. ,-'   ;` ;`,','_.--=:      /
//        |'':          ,'        :     ;` ;,;,,-'_.-._`.   ,'
//        '  :         ;_.-.      `.    :' ;;;'.ee.    \|  /
//         \.'    _..-'/8o. `.     :    :! ' ':8888)   || /
//          ||`-''    \\88o\ :     :    :! :  :`""'    ;;/
//          ||         \"88o\;     `.    \ `. `.      ;,'
//          /)   ___    `."'/(--.._ `.    `.`.  `-..-' ;--.
//          \(.="""""==.. `'-'     `.|      `-`-..__.-' `. `.
//           |          `"==.__      )                    )  ;
//           |   ||           `"=== '                   .'  .'
//           /\,,||||  | |           \                .'   .'
//            | |||'|' |'|'           \|             .'   _.' \
//            | |\' |  |           || ||           .'    .'    \
//            ' | \ ' |'  .   ``-- `| ||         .'    .'       \
//              '  |  ' |  .    ``-.._ |  ;    .'    .'          `.
//           _.--,;`.       .  --  ...._,'   .'    .'              `.__
//         ,'  ,';   `.     .   --..__..--'.'    .'                __/_\
//       ,'   ; ;     |    .   --..__.._.'     .'                ,'     `.
//      /    ; :     ;     .    -.. _.'     _.'                 /         `
//     /     :  `-._ |    .    _.--'     _.'                   |
//    /       `.    `--....--''       _.'                      |
//    `._              _..-'                         |
//       `-..____...-''                              |
//                                                   |
//                                                   |
//
//         Sound: https://www.youtube.com/watch?v=4F4qzPbcFiA
//
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

const int N = 1e3 + 5;

int n, m;
bool clr[N][N], cant[N][N];
bool used[N][N];
vector<int> who[2][N];

void dfs(int i, int j) {
    if (used[i][j]) return;
    used[i][j] = true;
    auto v = who[0][i];
    who[0][i].clear();
    for (auto q : v) dfs(i, q);
    v = who[1][j];
    who[1][j].clear();
    for (auto q : v) dfs(q, j);
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    cin >> n >> m;
    bool have = false;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '#') {
                have = true;
                who[0][i].push_back(j);
                who[1][j].push_back(i);
                clr[i][j] = true;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (who[0][i].empty()) {
            bool OK = false;
            for (int j = 0; j < m; ++j) {
                if (who[1][j].empty()) {
                    OK = true;
                }
            }
            if (!OK) {
                cout << -1 << '\n';
                return 0;
            }
            continue;
        }
        int sz = who[0][i].back() - who[0][i][0] + 1;
        if (sz != who[0][i].size()) {
            cout << -1 << '\n';
            return 0;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (who[1][i].empty()) {
            bool OK = false;
            for (int j = 0; j < n; ++j) {
                if (who[0][j].empty()) {
                    OK = true;
                }
            }
            if (!OK) {
                cout << -1 << '\n';
                return 0;
            }
            continue;
        }
        int sz = who[1][i].back() - who[1][i][0] + 1;
        if (sz != who[1][i].size()) {
            cout << -1 << '\n';
            return 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (clr[i][j] && !used[i][j]) {
                ++ans;
                dfs(i, j);
            }
        }
    }
    cout << ans << '\n';
}