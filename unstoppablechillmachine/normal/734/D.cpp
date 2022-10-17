/*














*/
/*  -
















*/
/*
  !










*/
/*

















*/
#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<ld> vld;
typedef vector<bool> vb;

#define f first
#define sec second
#define pb push_back
#define ppb pop_back
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (ll)(x).size()
#define rsz(Vec, x) Vec.resize(x);
#define pw(x) (1ll << (x))
#define sqr(x) ((x) * (x))
#define fro for
#define itn int
#define forn(i, n) for (int i(1); i <= n; i++)
#define fore(i, n) for (int i(0); i < n; i++)
#define chcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<int>(cout, " "))

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int SMAXN = 1e3 + 10;
const int P = 259;
const ll BINF = 1e18 + 10;
const ld EPS = 1e-6;
const ld PI = acos(-1);

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

inline void error()
{
    writeInt(-1);
    exit(0);
}

inline ll logn(ll n)
{
    ll xx = ll(log2(ld(n)));
	return xx;
}

inline ld rst(ll x, ll y, ll x2, ll y2)
{
    ld xx = x;
    ld yy = y;
    ld xx2 = x2;
    ld yy2 = y2;
    return sqrt((xx2 - xx) * (xx2 - xx) + (yy2 - yy) * (yy2 - yy));
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    ld bbr = 1e10, bmr = 1e10, mmr = 1e10, mbr = 1e10, mrr = 1e10, brr = 1e10, rbr = 1e10, rmr = 1e10;
    char bb = 'A', bm = 'A', mb = 'A', mm = 'A', mr = 'A', br = 'a', rb = 'a', rm = 'a';
    set<char> st;
    int n = readInt();
    ll x2 = readInt();
    ll y2 = readInt();
    forn(i, n)
    {
        char ch = readChar();
        ll x = readInt();
        ll y = readInt();
        if (x != x2 && y != y2 && abs(x2 - x) != abs(y2 - y)) continue;
        ld k = rst(x, y, x2, y2);
        if(x > x2 && y > y2)
        {
            if (bbr > k)
            {
                bbr = k;
                bb = ch;
            }
        }
        if (x > x2 && y < y2)
        {
            if (bmr > k)
            {
                bmr = k;
                bm = ch;
            }
        }
        if (x < x2 && y < y2)
        {
            if (mmr > k)
            {
                mmr = k;
                mm = ch;
            }
        }
        if (x < x2 && y > y2)
        {
            if (mbr > k)
            {
                mbr = k;
                mb = ch;
            }
        }
        if (x == x2 && y > y2)
        {
            if (rbr > k)
            {
                rbr = k;
                rb = ch;
            }
        }
        if (x == x2 && y < y2)
        {
            if (rmr > k)
            {
                rmr = k;
                rm = ch;
            }
        }
        if (x > x2 && y == y2)
        {
            if (brr > k)
            {
                brr = k;
                br = ch;
            }
        }
        if (x < x2 && y == y2)
        {
            if (mrr > k)
            {
                mrr = k;
                mr = ch;
            }
        }
    }

    st.ins(bm);
    st.ins(mb);
    st.ins(mm);
    st.ins(bb);
    if (st.find('B') != st.end() || st.find('Q') != st.end())
    {
        writeWord("YES");
        exit(0);
    }
    st.clear();
    st.ins(br);
    st.ins(mr);
    st.ins(rb);
    st.ins(rm);
    if (st.find('Q') != st.end() || st.find('R') != st.end())
    {
        writeWord("YES");
        exit(0);
    }

    writeWord("NO");

    return 0;
}