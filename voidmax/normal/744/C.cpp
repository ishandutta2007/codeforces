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

const string FILENAME = "input";
const int MAXN = 1 << 16, MAXK = 16 * 16;

short int dp[MAXN][MAXK + 1][2];
int n;
vector <int> f;
vector <pair <int, int>> cost;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    //read(FILENAME);
    cin >> n;
    f.resize(n);
    cost.resize(n);
    long long sl = 0, sr = 0;
    for (int i = n; i--;) {
        char c; 
        cin >> c;
        f[i] = c == 'B';
        cin >> cost[i].x >> cost[i].y;
        if (cost[i].x > n) {
            sl += cost[i].x - n;
            cost[i].x = n;
        }
        if (cost[i].y > n) {
            sr += cost[i].y - n;
            cost[i].y = n;
        }
    }

    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j <= MAXK; ++j) {
            dp[i][j][0] = dp[i][j][1] = n * n;
        }
    }
    if (sr >= sl) {
        dp[0][min((long long)n * n, sr - sl)][0] = 0;
    } else {
        dp[0][min((long long)n * n, sl - sr)][1] = 0;
    }
    for (int i = 0; i + 1 < (1 << n); ++i) {
        int R = 0, B = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                if (!f[j]) {
                    ++R;
                } else {
                    ++B;
                }
            }
        }
        //cout << "     " << i << endl;
        for (int j = 0; j < n; ++j) {
            if ((i & (1 << j)) == 0) {
                //cout << " ???? " << j << endl;
                int l = max(cost[j].x - R, 0), r = max(cost[j].y - B, 0);
                int ln, rn, c;
                for (int p = 0; p < 2; ++p) {
                    for (int k = 0; k <= n * n; ++k) {
                        if (dp[i][k][p] > (n * n)) continue;
                        ln = k, rn = 0;
                        c = max(0, max(l - ln, r - rn));
                        ln += c - l;
                        rn += c - r;
                        if (dp[i][k][p] + c > (n * n)) continue;
                        if (ln == 0) {
                            chkmin(dp[i ^ (1 << j)][min(n * n, rn)][p ^ 1], dp[i][k][p] + c);
                        } else {
                            chkmin(dp[i ^ (1 << j)][min(n * n, ln)][p], dp[i][k][p] + c);
                        }
                    }
                    swap(l, r);
                }
            }
        }
    }
    int ans = n * n;
    for (int r = 0; r < 2; ++r) {
        for (int k = 0; k <= n * n; ++k) {
            chkmin(ans, dp[(1 << n) - 1][k][r]);
        }
    }
    cout << max(sl, sr) + ans + n << endl;
}