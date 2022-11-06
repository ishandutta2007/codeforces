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

int n;
int min_elem[1001];
int res[1001];
vector <int> w[41];
vector <int> p[41];

void get(int L, int R, int c) {
    if (L == R) return;
    assert(c < 20);
    int M = (L + R) >> 1;
    for (int i = M + 1; i <= R; ++i) {
        w[c].pb(i);
    }
    for (int i = L; i <= M; ++i) {
        p[c].pb(i);
    }
    ++c;
    for (int i = L; i <= M; ++i) {
        w[c].pb(i);
    }
    for (int i = M + 1; i <= R; ++i) {
        p[c].pb(i);
    }
    ++c;
    get(L, M, c);
    get(M + 1, R, c);
} 

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    //read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        min_elem[i] = 1e9;
    }
    get(0, n - 1, 0);
    for (int j = 0; j < 20; ++j) {
        if (w[j].size() == 0) break;
        cout << w[j].size() << endl;
        for (int i: w[j]) {
            cout << i + 1 << ' ';
        }
        cout << endl;
        for (int i = 0; i < n; ++i) {
            cin >> res[i];
        }
        for (int i: p[j]) {
            chkmin(min_elem[i], res[i]);
        }
    }
    cout << -1 << endl;
    for (int i = 0; i < n; ++i) {
        cout << min_elem[i] << ' ';
    }
}