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
#define f first
#define s second
const string FILENAME = "input";
typedef pair <int, int> point;

bool okch(char a, char b) {
    if (a == '*')
        return true;
    return a == b;
}

bool ok(string & st, string & kek, vector<bool> & opened) {
    for (int i = 0; i < sz(st); ++i)
        if ((!okch(st[i], kek[i])) || (opened[kek[i] - 'a'] && st[i] == '*'))
            return false;  
    return true;
}

vector<bool> get(string & st, string & kek) {
    vector<bool> res(26, false);
    for (int i = 0; i < sz(st); ++i) {
        if (st[i] == '*')
            res[kek[i] - 'a'] = true;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    // read(FILENAME);
    int n;
    cin >> n;
    string st;
    cin >> st;
    int m;
    cin >> m;
    vector<bool> ans(26, true), opened(26, false);
    for (char i : st) {
        if (i != '*') {
            ans[i - 'a'] = false;
            opened[i - 'a'] = true;
        }
    }
    for (int i = 0; i < m; ++i) {
        string kek;
        cin >> kek;
        if (!ok(st, kek, opened)) continue;
        vector<bool> letters = get(st, kek);
        for (int j = 0; j < 26; ++j) {
            ans[j] = (ans[j] & letters[j]);
        }
    }
    int res = 0;
    for (int i = 0; i < 26; ++i)
        res += ans[i];
    cout << res;
}