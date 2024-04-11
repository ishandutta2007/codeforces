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

/** Read */

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

const int MAXN = 2e5 + 1, LOG = 31;

int n, a, b;
vector <pair <double, double>> car;
int ans[2002][2002];

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    //read(FILENAME);
    scanf("%d%d%d", &n, &a, &b);
    car.resize(n);
    for (int i = n; i--;)
        scanf("%lf", &car[i].x);
    for (int i = n; i--;)
        scanf("%lf", &car[i].y);
    for (int i = 0; i < n; ++i) {
        int A = car[i].x * 1000000;
        int B = car[i].y * 1000000;
        int C = (car[i].x + car[i].y - car[i].x * car[i].y) * 1000000;
        int k1 = min(a, i) + 1, k2 = min(b, i) + 1;
        for (int j = k1; j--;) {
            for (int q = k2; q--;) {
                //chkmax(ans[j][q], ans[j][q]);
                chkmax(ans[j + 1][q], ans[j][q] + A);
                chkmax(ans[j][q + 1], ans[j][q] + B);
                chkmax(ans[j + 1][q + 1], ans[j][q] + C);
            }
        } 
    }
    cout << fixed << (double)ans[a][b] / 1000000 << endl; 
}