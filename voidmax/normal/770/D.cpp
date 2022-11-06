/*
  !










*/
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
  
using namespace std;


#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define prev prev228
const int MAXN = 101;


int n;
string ss;
int c[MAXN];
char s[10 * MAXN][10 * MAXN];


int main() {
    cin >> n;
    cin >> ss;
    int bal = 0;
    int deep = 0;
    for (int i = 0; i < n; i++) {
        if (ss[i] == '[') {
            bal++;
        }
        c[i] = bal;
        deep = max(deep, bal);
        if (ss[i] == ']') {
            bal--;
        }
    }
    for (int i = 0; i < n; i++) {
        c[i] = deep - c[i] + 1;
    }
    int uk = -1;
    for (int i = 0; i < n; i++) {
        uk++;
        s[deep][uk] = '|';
        for (int j = deep - 1; j >= deep - c[i] + 1; j--) {
            s[j][uk] = '|';
        }
        s[deep - c[i]][uk] = '+';
        for (int j = deep + 1; j < deep + c[i]; j++) {
            s[j][uk] = '|';
        }
        s[deep + c[i]][uk] = '+';
        if (ss[i] == '[') {
            s[deep - c[i]][uk + 1] = '-';
            s[deep + c[i]][uk + 1] = '-';
        } else {
            s[deep - c[i]][uk - 1] = '-';
            s[deep + c[i]][uk - 1] = '-';
        }
        if (ss[i] == '[' && ss[i + 1] == ']') {
            uk+= 3;
        }
    }
    for (int i = 0; i < 2 * deep + 1; i++) {
        for (int j = 0; j <= uk; j++) {
            if (s[i][j] == 0) {
                s[i][j] = ' ';
            }
            writeChar(s[i][j]);
        }
        writeChar('\n');
    }
    return 0;
}