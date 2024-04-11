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
//    `._              _..-'                                   |
//       `-..____...-''                                        |
//                                                             |
//                                                             |
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

const int N = 1e6 + 5;

int n, m, t;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

bool clr[1001][1001];
short int dist[1001][1001];

int cnt = 0;

void dfs(int x, int y) {
    if (dist[x][y] == 0) return;
    dist[x][y] = 0;
    ++cnt;
    for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (clr[x][y] != clr[nx][ny]) continue;
        dfs(nx, ny);
    }
}

queue<pair<short, short>> que;

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    cin >> n >> m >> t;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            clr[i][j] = s[j] == '1';
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dist[i][j] = 5000;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int old_cnt = cnt;
            dfs(i, j);
//            cout << old_cnt << ' ' << cnt << endl;
            if (cnt - old_cnt == 1) {
                dist[i][j] = 5000;
            } else {
                que.push({i, j});
            }
        }
    }
    while (que.size()) {
        auto [x, y] = que.front();
        que.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                que.push({nx, ny});
            }
        }
    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cout << '\t' << dist[i][j];
//        }
//        cout << '\n';
//    }
    for (int i = 0; i < t; ++i) {
        int x, y;
        long long dt;
        cin >> x >> y >> dt;
        --x, --y;
        if (dist[x][y] == 5000 || dist[x][y] >= dt)  {
            cout << clr[x][y] << '\n';
            continue;
        }
        cout << ((int)clr[x][y] ^ ((dt - dist[x][y]) & 1)) << '\n';
    }
}