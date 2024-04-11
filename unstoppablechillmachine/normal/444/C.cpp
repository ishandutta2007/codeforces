//I_l_M_P
#include <bits/stdc++.h>

#ifdef FAST_ALLOCATOR_MEMORY
    int allocator_pos = 0;
    char allocator_memory[(int)FAST_ALLOCATOR_MEMORY];
    inline void * operator new ( size_t n ) {
        char *res = allocator_memory + allocator_pos;
        allocator_pos += n;
        assert(allocator_pos <= (int)FAST_ALLOCATOR_MEMORY);
        return (void *)res;
    }
    inline void operator delete ( void * ) noexcept { }
    //inline void * operator new [] ( size_t ) { assert(0); }
    //inline void operator delete [] ( void * ) { assert(0); }
#endif

template <class T = int> inline T readInt();
inline double readDouble();
inline int readUInt();
inline int readChar();
inline void readWord(char *s);
inline bool readLine(char *s);
inline bool isEof();
inline int getChar();
inline int peekChar();
inline bool seekEof();
inline void skipBlanks();

template <class T> inline void writeInt(T x, char end = 0, int len = -1);
inline void writeChar(int x);
inline void writeWord(const char *s);
inline void writeDouble(double x, int len = 0);
inline void flush();

static struct buffer_flusher_t {
    ~buffer_flusher_t() {
        flush();
    }
} buffer_flusher;

static const int buf_size = 4096;

static unsigned char buf[buf_size];
static int buf_len = 0, buf_pos = 0;

inline bool isEof() {
    if (buf_pos == buf_len) {
        buf_pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
        if (buf_pos == buf_len)
            return 1;
    }
    return 0;
}

inline int getChar() {
    return isEof() ? -1 : buf[buf_pos++];
}

inline int peekChar() {
    return isEof() ? -1 : buf[buf_pos];
}

inline bool seekEof() {
    int c;
    while ((c = peekChar()) != -1 && c <= 32)
        buf_pos++;
    return c == -1;
}

inline void skipBlanks() {
    while (!isEof() && buf[buf_pos] <= 32U)
        buf_pos++;
}

inline int readChar() {
    int c = getChar();
    while (c != -1 && c <= 32)
        c = getChar();
    return c;
}

inline int readUInt() {
    int c = readChar(), x = 0;
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return x;
}

template <class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    else if (c == '+')
        c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}

inline double readDouble() {
    int s = 1, c = readChar();
    double x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    if (c == '.') {
        c = getChar();
        double coef = 1;
        while ('0' <= c && c <= '9')
            x += (c - '0') * (coef *= 1e-1), c = getChar();
    }
    return s == 1 ? x : -x;
}

inline void readWord(char *s) {
    int c = readChar();
    while (c > 32)
        *s++ = c, c = getChar();
    *s = 0;
}

inline bool readLine(char *s) {
    int c = getChar();
    while (c != '\n' && c != -1)
        *s++ = c, c = getChar();
    *s = 0;
    return c != -1;
}

static int write_buf_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
    if (write_buf_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_buf_pos = 0;
    write_buf[write_buf_pos++] = x;
}

inline void flush() {
    if (write_buf_pos) {
        fwrite(write_buf, 1, write_buf_pos, stdout), write_buf_pos = 0;
        fflush(stdout);
    }
}

template <class T>
inline void writeInt(T x, char end, int output_len) {
    if (x < 0)
        writeChar('-'), x = -x;
    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n < output_len)
        s[n++] = '0';
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}

inline void writeWord(const char *s) {
    while (*s)
        writeChar(*s++);
}

inline void writeDouble(double x, int output_len) {
    if (x < 0)
        writeChar('-'), x = -x;
    int t = (int)x;
    writeInt(t), x -= t;
    writeChar('.');
    for (int i = output_len - 1; i > 0; i--) {
        x *= 10;
        t = std::min(9, (int)x);
        writeChar('0' + t), x -= t;
    }
    x *= 10;
    t = std::min(9, (int)(x + 0.5));
    writeChar('0' + t);
}

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;

//const int MAX_MEM = 1e8; int mpos = 0; char mem[MAX_MEM]; inline void * operator new ( size_t n ) { char *res = mem + mpos; mpos += n; assert(mpos <= MAX_MEM); return (void *)res; } inline void operator delete ( void * ) { }

typedef long double ld;
typedef long long ll;

#define _ inline
#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

struct SQRT_Decomposition {
    vector<int> L, R, T, set_val, arr;
    vector<ll> add, val, sum;
    int n, cnt_blocks, len;
    SQRT_Decomposition(int _n) {
        n = _n;
        arr.rsz(n);
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }
        val.rsz(n, 0);
        build();
    }
    void build() {
        cnt_blocks = sqrt(n), len = n / cnt_blocks;
        if (cnt_blocks * len < n) {
            len++;
        }
        L.rsz(cnt_blocks);
        R.rsz(cnt_blocks);
        T.rsz(cnt_blocks);
        set_val.rsz(cnt_blocks);
        add.rsz(cnt_blocks);
        sum.rsz(cnt_blocks);
        for (int i = 0; i < cnt_blocks; i++) {
            L[i] = i * len;
            R[i] = min(n, len * (i + 1)) - 1;
            T[i] = i;
            set_val[i] = -1;
            add[i] = 0;
            sum[i] = 0;
            for (int j = L[i]; j <= R[i]; j++) {
                sum[i] += val[j];
            }
        }
    }
    void rebuild() {
        for (auto it : T) {
            for (int i = L[it]; i <= R[it]; i++) {
                val[i] += add[it];
                if (set_val[it] != -1) {
                    arr[i] = set_val[it];
                }
            }
        }
        build();
    }
    void create_new_block(int l, int r, int vl, ll push) {
        L.pb(l);
        R.pb(r);
        set_val.pb(vl);
        add.pb(push);
        sum.pb(0);
        for (int i = l; i <= r; i++) {
            sum[cnt_blocks] += val[i];
        }
        sum[cnt_blocks] += push * (r - l + 1);
        cnt_blocks++;
    }
    void split(int x) {
        int ind = -1, pos = 0;
        for (auto it : T) {
            if (L[it] <= x && R[it] >= x) {
                ind = it;
                break;
            }
            pos++;
        }
        if (ind == -1 || R[ind] == x) {
            return;
        }
        create_new_block(L[ind], x, set_val[ind], add[ind]);
        create_new_block(x + 1, R[ind], set_val[ind], add[ind]);
        vector<int> T2;
        for (int i = 0; i < pos; i++) {
            T2.pb(T[i]);
        }
        T2.pb(cnt_blocks - 2);
        T2.pb(cnt_blocks - 1);
        for (int i = pos + 1; i < T.size(); i++) {
            T2.pb(T[i]);
        }
        T = T2;
    }
    void paint(int block, int color) {
        if (set_val[block] != -1) {
            sum[block] += abs(set_val[block] - color) * (R[block] - L[block] + 1);
            add[block] += abs(set_val[block] - color);
        }
        else {
            for (int i = L[block]; i <= R[block]; i++) {
                sum[block] += abs(arr[i] - color);
                val[i] += abs(arr[i] - color);
            }
        }
        set_val[block] = color;
    }
    void update(int l, int r, int color) {
        split(l - 1);
        split(r);
        for (auto it : T) {
            if (L[it] >= l && R[it] <= r) {
                paint(it, color);
            }
        }
    }
    ll get_sum(int l, int r) {
        split(l - 1);
        split(r);
        ll ans = 0;
        for (auto it : T) {
            if (L[it] >= l && R[it] <= r) {
                ans += sum[it];
            }
        }
        return ans;
    }
};

_ void source() {
    int n = readInt(), m = readInt();
    SQRT_Decomposition A(n);
    int sz = sqrt(n);
    for (int i = 1; i <= m; i++) {
        if (i % sz == 0) {
            A.rebuild();
        }
        int type = readInt(), l = readInt(), r = readInt();
        l--, r--;
        if (type == 1) {
            int color = readInt();
            A.update(l, r, color);
        }
        else {
            writeInt<ll>(A.get_sum(l, r), '\n');
        }
    }
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    source();
    return 0;
}