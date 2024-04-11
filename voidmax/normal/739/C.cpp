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

const int MAXN = 3e5 + 1, LOG = 31;

int sign(int d) {
    if (d == 0)
        return 0;
    return d / abs(d);
}

struct seg_tree {
    struct node {
        int ls[3], ans, rs[3], len;
        node() {
            len = 1;
            ls[0] = ls[1] = ls[2] = ans = rs[0] = rs[1] = rs[2] = 0;
        }
        node(int flag, int s = 1) {
            len = s;
            ls[0] = !flag;
            ls[1] = flag;
            ls[2] = 1;
            ans = 1;
            rs[0] = !flag;
            rs[1] = flag;
            rs[2] = 1;
        }
    };
    node merge(node a, node b) {
        node c;
        c.len = a.len + b.len;
        c.ans = max(a.ans, b.ans);
        chkmax(c.ans, a.rs[0] + b.ls[2]);
        chkmax(c.ans, a.rs[2] + b.ls[1]);
        c.ls[0] = a.ls[0];
        if (a.len == a.ls[0]) 
            c.ls[0] += b.ls[0];
        c.ls[1] = a.ls[1];
        if (a.len == a.ls[1]) 
            c.ls[1] += b.ls[1];
        c.rs[0] = b.rs[0];
        if (b.len == b.rs[0]) {
            c.rs[0] += a.rs[0];
        }
        c.rs[1] = b.rs[1];
        if (b.len == b.rs[1]) {
            c.rs[1] += a.rs[1];
        }
        c.ls[2] = a.ls[2];
        if (a.len == a.ls[0]) {
            c.ls[2] = a.ls[0] + b.ls[2];
        } else if (a.len == a.ls[2]) {
            c.ls[2] += b.ls[1];
        }
        c.rs[2] = b.rs[2];
        if (b.len == b.rs[1]) {
            c.rs[2] = a.rs[2] + b.len;
        } else if (b.len == b.rs[2]) {
            c.rs[2] += a.rs[0];
        }
        chkmax(c.ls[2], c.ls[0]);
        chkmax(c.ls[2], c.ls[1]);
        chkmax(c.rs[2], c.rs[0]);
        chkmax(c.rs[2], c.rs[1]);
        /*cout << "a: " << a.len << ' ' << a.ls[0] << ' ' << a.ls[1] << ' ' << a.ls[2] << '[' << a.ans << ']' << a.rs[0] << ' ' << a.rs[1] << ' ' << a.rs[2] << endl;
        cout << "b: " << b.len << ' ' << b.ls[0] << ' ' << b.ls[1] << ' ' << b.ls[2] << '[' << b.ans << ']' << b.rs[0] << ' ' << b.rs[1] << ' ' << b.rs[2] << endl;
        cout << "c: " << c.len << ' ' << c.ls[0] << ' ' << c.ls[1] << ' ' << c.ls[2] << '[' << c.ans << ']' << c.rs[0] << ' ' << c.rs[1] << ' ' << c.rs[2] << endl;
        cout << endl;*/
        return c;
    }
    int n;
    vector <node> tree;
    vector <long long> arr;
    void resize(int s) {
        n = 1;
        while (s >= n)
            n <<= 1;
        tree.resize(n * 2);
        arr.resize(n * 2, 0);
    }
    void change(int i, int d) {
        i += n;
        arr[i] -= d;
        tree[i] = node();
        if (arr[i] < 0) tree[i] = node(0);
        if (arr[i] > 0) tree[i] = node(1);
        while (i > 1) {
            i >>= 1;
            tree[i] = merge(tree[i * 2], tree[i * 2 + 1]);
        }
    }
    int get() {
        return tree[1].ans + 1;
    }
};

int n, m, L, R, d;
int arr[MAXN];
seg_tree box;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    //read(FILENAME);
    n = readInt();
    box.resize(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = readInt();
        if (i != 0)
            box.change(i - 1, arr[i] - arr[i - 1]);
    }
    m = readInt();
    for (int j = m; j--;) {
        L = readInt() - 1;
        R = readInt() - 1;
        d = readInt();
        if (L != 0) {
            box.change(L - 1, d);
        }
        /*
        for (int i = 0; i < n; ++i) 
            cout << box.arr[i + box.n] << ' ';
        cout << endl;
        cout << box.tree[1].ans << endl;
        */
        if (R != n - 1)
            box.change(R, -d);
        /*
        for (int i = 0; i < n; ++i) 
            cout << box.arr[i + box.n] << ' ';
        cout << endl;
        cout << box.tree[1].ans << endl;
        */
        writeInt(box.get(), '\n');
    }
    //cout << endl;
    /*
    for (int i = 0; i < n; ++i) 
        cout << sign(box.arr[i + box.n]) << ' ';
    cout << endl;
    cout << box.tree[1].ans << endl;
    */

}