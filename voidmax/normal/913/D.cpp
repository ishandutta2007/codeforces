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
#define pb push_back
#define x first
#define y second
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;

inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );
          
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
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";
const int MAXN = 2e5 + 1;



int n, T;
int a[MAXN], t[MAXN];
vector<int> event[MAXN];
typedef pair<int, int> point;

long long sumt = 0;
set<pair<int, int>> que[2];
set<pair<int, int>> res[2];

int rep = 0, cnt = 0;

void find_ans(bool need = false) {
    if (need && rep == 0) {
        cout << "0\n0\n\n";
        exit(0);
    }
    for (int i = 0; i < n; ++i) {
        que[1].insert(make_pair(t[i], i));
    }
    for (int i = 0; i <= n; ++i) {
        for (int j : event[i]) {
            auto w = make_pair(t[j], j);
            if (que[1].count(w)) {
                que[1].erase(w);
                que[0].insert(w);
            }
            if (res[1].count(w)) {
                res[1].erase(w);
                res[0].insert(w);
            }
        }
        if (i == 0) continue;
        for (int t = 0; t < 2; ++t) { 
            while (que[t].size() && res[t].size()) {
                auto w = *que[t].begin();
                auto u = *res[t].rbegin();
                if (w.x < u.x) {
                    sumt += w.x;
                    sumt -= u.x;
                    que[t].erase(w);
                    res[t].insert(w);
                    res[t].erase(u);
                    que[t].insert(u);
                } else {
                    break;
                }
            }
        }
        while (que[1].size() && res[0].size()) {
            auto w = *que[1].begin();
            auto u = *res[0].rbegin();
            if (sumt + w.x - u.x <= T) {
                sumt += w.x - u.x;
                que[1].erase(w);
                res[1].insert(w);
                res[0].erase(u);
                que[0].insert(u);
            } else {
                break;
            }
        }
        bool OK = false;
        if (que[1].size()) {
            auto w = *que[1].begin();
            if (sumt + w.x <= T) {
                sumt += w.x;
                res[1].insert(w);
                que[1].erase(w);
                OK = true;
            }
        }
        if (!OK) {
            while ((res[1].size() + res[0].size()) != i) {
                if (que[0].size() == 0) break;
                auto w = *que[0].begin();
                if (sumt + w.x <= T) {
                    sumt += w.x;
                    res[0].insert(w);
                    que[0].erase(w);
                } else {
                    if (res[1].size() == 0) break;
                    sumt -= (*res[1].rbegin()).x;
                    que[1].insert(*res[1].rbegin());
                    res[1].erase(*res[1].rbegin());
                }
            }
        }
        if ((res[0].size() + res[1].size()) == i) {
            if (res[1].size() > rep) {
                rep = res[1].size();
                cnt = i;
            }
        } else {
            break;
        }
        if (need && i == cnt) {
            cout << rep << '\n';
            cout << i << '\n';
            for (auto j : res[0]) cout << j.y + 1 << ' ';
            for (auto j : res[1]) cout << j.y + 1 << ' ';
            cout << '\n';
            exit(0);
        } 
    }
    res[0].clear();
    que[0].clear();
    res[1].clear();
    que[1].clear();
    sumt = 0;
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    //read(FILENAME);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> T;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> t[i];
        event[a[i] + 1].pb(i);  
    }
    find_ans();
    find_ans(true);
}