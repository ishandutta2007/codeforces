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
int n[2], m[2];
bitset <801> good[401];
bitset <801> used[401][26];

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    //read(FILENAME);
    n[0] = readInt();
    m[0] = readInt();
    for (int i = 0; i < n[0]; ++i) {
        for (int j = 0; j < m[0]; ++j) {
            char a = readChar();
            good[i][j] = true;
            used[i][a - 'a'][j] = used[i][a - 'a'][j + m[0]] = true;
        }
    }
    n[1] = readInt();
    m[1] = readInt();
    for (int i = 0; i < n[1]; ++i) {
        for (int j = 0; j < m[1]; ++j) {
            char a = readChar();
            if (a == '?') continue;
            for (int k = 0; k < n[0]; ++k) {
                int X = (i + k) % n[0], Y = j % m[0];
                good[k] &= used[X][a - 'a'] >> Y;
            }
        }
    }
    for (int i = 0; i < n[0]; ++i) {
        for (int j = 0; j < m[0]; ++j) {
            if (good[i][j]) {
                writeChar('1');
            } else {
                writeChar('0');
            }
        }
        writeChar('\n');
    }
}