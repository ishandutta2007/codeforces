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
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Out(i, a, b) for (int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".in").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x );
inline void writeWord( const char *s );

static const int buf_size = 4096;

inline int getChar() {
    static char buf[buf_size];
    static int len = 0, pos = 0;
    if (pos == len)
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    if (pos == len)
        return -1;
    return buf[pos++];
}

inline int readChar() {
    int c = getChar();
    while (c <= 32)
        c = getChar();
    return c;
}

template <class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    //if (c == '-')
    //    s = -1, c = getChar();
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
    //if (x < 0)
    //    writeChar('-'), x = -x;

    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}

inline void writeWord( const char *s ) {
    while (*s)
        writeChar(*s++);
}

struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;

const string FILENAME = "input";
typedef long long base;
const int MAXN = 5e5 + 1, MAXMASK = 1 << 22;

int n;
int s[MAXN];
vector <pair <int, int>> edge[MAXN];

void dfs_size_count(int i) {
    s[i] = 1;
    for (auto j: edge[i]) {
        dfs_size_count(j.x);
        s[i] += s[j.x];
    }
}

struct bag {
    int ans, ans_one, cnt;
    int used[MAXMASK];
    int h[MAXMASK];
    bag() {
        ans = 0;
        cnt = 1;
    }
    void push(int m) {
        if (used[m] != cnt) {
            used[m] = cnt;
            h[m] = -1e9;
        }
    }
    int try_add(int m, int h_now) {
        push(m);
        int nans = ans;
        chkmax(nans, h[m] + h_now);
        for (int i = 0; i < 22; ++i) {
            int nm = m ^ (1 << i);
            push(nm);
            chkmax(nans, h[nm] + h_now);
        }
        return nans;
    }
    void add_mask(int m, int h_now) {
        ans = try_add(m, h_now);
        chkmax(h[m], h_now);
    }
    void clear() {
        ans = 0;
        ans_one = 0;
        ++cnt;
    }
};

int ans[MAXN];
bag box;

void dfs_no_update(int i, int h, int mask, vector <pair <int, int>> &subtree) {
    subtree.pb({mask, h});
    for (auto j: edge[i]) {
        dfs_no_update(j.x, h + 1, mask ^ (1 << j.y), subtree);
    }
} 

void dfs_ans(int i, int h, int mask) {
    if (edge[i].size() != 0) {
        auto ms = edge[i][0];
        for (auto j: edge[i]) {
            if (s[ms.x] < s[j.x]) {
                ms = j;
            }
        } 
        for (auto j: edge[i]) {
            if (j == ms) continue;
            dfs_ans(j.x, h + 1, mask ^ (1 << j.y));
            chkmax(ans[i], ans[j.x]);
            box.clear();
        }
        dfs_ans(ms.x, h + 1, mask ^ (1 << ms.y));
        box.ans = 0;
        chkmax(ans[i], ans[ms.x]);
        for (auto j: edge[i]) {
            if (j == ms) continue;
            vector <point> subtree; 
            dfs_no_update(j.x, h + 1, mask ^ (1 << j.y), subtree);
            int res = box.ans;
            for (auto q: subtree) {
                chkmax(res, box.try_add(q.x, q.y));
            } 
            for (auto q: subtree) {
                box.add_mask(q.x, q.y);
            }
            box.ans = res;
        }
    }
    box.add_mask(mask, h);
    ans[i] = max(ans[i], box.ans - h * 2);
}

int main(int argc, char const *argv[]) {
    srand(time(0));
    ios::sync_with_stdio(false);
    //read(FILENAME);
    n = readInt();
    for (int i = 1; i < n; ++i) {
        int L = readInt() - 1;
        char c = readChar();
        edge[L].pb({i, c - 'a'});
    }
    dfs_size_count(0);
    dfs_ans(0, 0, 0);
    for (int i = 0; i < n; ++i) {
        writeInt(ans[i], ' ');
    }
    writeChar('\n');
}