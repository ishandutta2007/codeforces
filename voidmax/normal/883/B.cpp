/*
  !
















*/
#pragma GCC optimize "-O3"
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
#include <stack>
#include <deque>
    
     
     
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
/** Interface */
     
inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );
     
/** Read */
     
static const int buf_size = 4096;
     
inline int getChar() {
    static char buf[buf_size];
    static int len = 0, pos = 0;
    if (pos == len) {
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    }
    if (pos == len) {
        return -1;
    }
    return buf[pos++];
}
     
inline int readChar() {
    int c = getChar();
    while (c <= 32) {
        c = getChar();
    }
    return c;
}
     
template <class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}
     
/** Write */
     
static int write_pos = 0;
static char write_buf[buf_size];
     
inline void writeChar( int x ) {
    if (write_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}
     
template <class T> 
inline void writeInt( T x, char end ) {
    if (x < 0)
        writeChar('-'), x = -x;
     
    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}
     
inline void writeWord( const char *s ) {     while (*s)
writeChar(*s++); }
     
struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;   
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define x first
#define y second
const string FILENAME = "input";
typedef pair <int, int> point;
const int MAXN = 3e5 + 1;

int n, m, k;
vector <int> edge[MAXN];
bool used[MAXN];

int minc[MAXN], maxc[MAXN], c[MAXN], nc[MAXN];
vector <int> top_sort;

vector <int> event[MAXN];
set <pair <int, int>> res;
set <int> need;

void dfs(int i) {
    used[i] = true;
    for (int j : edge[i]) {
        if (!used[j]) {
            dfs(j);
        }
    }
    top_sort.pb(i);
}

int main() {
    ios::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //read(FILENAME);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        --c[i];
        nc[i] = c[i];
        if (c[i] != -1) need.insert(c[i]);
        maxc[i] = k - 1;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> b >> a;
        edge[a - 1].pb(b - 1);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) { 
            dfs(i);
        }
    }
    reverse(top_sort.begin(), top_sort.end());
    for (int i : top_sort) {
        if (c[i] == -1) {
            nc[i] = min(minc[i], k - 1);
        } 
        used[i] = false;
        for (int j : edge[i]) {
            chkmax(minc[j], nc[i] + 1);
        }

    }
    reverse(top_sort.begin(), top_sort.end());
    for (int i : top_sort) {
        if (c[i] != -1) {
            maxc[i] = c[i];
        } else {
            for (int j : edge[i]) {
                chkmin(maxc[i], maxc[j] - 1);
            }
            chkmax(maxc[i], 0);
            event[maxc[i]].pb(i);
        }
    }
    // for (int i = 0; i < n; ++i) {
    //     if (c[i] == -1) cout << "(";
    //     cout << minc[i] + 1;
    //     if (c[i] == -1) cout << ")";
    //     cout << ' ';
    // }
    // cout << endl;
    // for (int i = 0; i < n; ++i) {
    //     if (c[i] == -1) cout << "(";
    //     cout << maxc[i] + 1;
    //     if (c[i] == -1) cout << ")";
    //     cout << ' ';
    // }
    // cout << endl;
    for (int id = k; id--;) {
        for (auto i : event[id]) res.insert({nc[i], i});
        if (need.count(id)) continue;
        while (res.size()) {
            auto t = *res.rbegin();
            res.erase(t);
            if (minc[t.y] <= id && id <= maxc[t.y]) {
                c[t.y] = id;
                need.insert(id);
                break;
            } else {
                c[t.y] = t.x;
                need.insert(t.x);
            }
        }
    }
    while (res.size()) {
        auto t = *res.rbegin();
        res.erase(t);
        c[t.y] = t.x;
    }
    for (int i = 0; i < n; ++i) {
        for (int j : edge[i]) {
            if (c[i] >= c[j]) {
                cout << -1 << endl;
                exit(0);
            }
        }
    }
    if (need.size() != k) {
        cout << -1 << endl;
        exit(0);
    }
    for (int i = 0; i < n; ++i) {
        cout << c[i] + 1 << ' ';
    }
}