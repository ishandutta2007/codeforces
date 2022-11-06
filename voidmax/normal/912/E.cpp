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
const int MAXN = 1e5 + 1;

int n;
long long k;
vector<int> p[3];
vector<long long> res[2];

void get(int i, vector<int> &p, long long n, long long cur = 1) {
    if (i == p.size()) {
        res[0].pb(cur);
        return;
    }
    get(i + 1, p, n, cur);
    while (n / p[i] >= cur) {
        cur *= p[i];
        get(i + 1, p, n, cur);
    }
}

bool check(long long M) {
    long long cnt = 0;
    int R = res[1].size() - 1;
    for (auto i : res[0]) {
        while (R >= 0 && M / i < res[1][R]) --R;
        cnt += R + 1;
    }
    return cnt >= k;
} 

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    //read(FILENAME);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    p[0].resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[0][i];
    }
    cin >> k;
    sort(p[0].begin(), p[0].end());
    for (int i = 0; i < n; ++i)
        p[1 + (i & 1)].pb(p[0][i]);
    get(0, p[1], 1e18);
    swap(res[0], res[1]);
    get(0, p[2], 1e18);
    sort(res[0].begin(), res[0].end());
    sort(res[1].begin(), res[1].end());
    long long L = 0, R = 1e18;
    while (R - L > 1) {
        auto M = (L + R) >> 1;
        if (check(M)) {
            R = M;
        } else {
            L = M;
        }
    }
    cout << R << endl;
}