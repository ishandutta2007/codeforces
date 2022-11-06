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
typedef long long base;
const int MAXN = 2e3 + 1;

int n, m, W;
int lst = 0;
int ans[1001][2];
int w[1001];
int b[1001];

bool used[1001];
vector <int> edge[1001];

void dfs(int i, vector <int> &comp) {
    if (used[i]) return;
    comp.pb(i);
    used[i] = true;
    for (int j: edge[i])
        dfs(j, comp);
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    //read(FILENAME);
    cin >> n >> m >> W;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        int L, R;
        cin >> L >> R;
        --L, --R;
        edge[L].pb(R);
        edge[R].pb(L);
    }
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        vector <int> comp;
        dfs(i, comp);
        int sumw = 0, sumb = 0;
        for (int j: comp) {
            sumw += w[j];
            sumb += b[j];
            for (int k = 0; k + w[j] <= W; ++k) {
                chkmax(ans[k + w[j]][!lst], ans[k][lst] + b[j]);
            }
        }
        for (int k = 0; k + sumw <= W; ++k) {
            chkmax(ans[k + sumw][!lst], ans[k][lst] + sumb);
        }
        for (int k = 0; k <= W; ++k) {
            chkmax(ans[k][!lst], ans[k][lst]);
        }
        lst ^= 1;
    }
    int res = 0;
    for (int k = 0; k <= W; ++k) {
        chkmax(res, ans[k][lst]);
    }
    cout << res << endl;
}