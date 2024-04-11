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
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (ll)(x).size()
#define rsz(Vec, x) Vec.resize(x);
#define fro for
#define itn int
#define forn(i, n) for (int i(1); i <= n; i++)
#define fore(i, n) for (int i(0); i < n; i++)
#define chcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<int>(cout, " "))

const int INF = 1e9 + 10;
const int MOD = 1e6;
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

bool used[MAXN];
int ans = -INF, arr[MAXN], arr1[MAXN], n, a, b, maxi, max1 = -INF, cnt, sum;
vvi Vec;

void dfs(int v, int rk)
{
    used[v] = true;
    arr1[v] += rk;
    fore(i, sz(Vec[v]))
    {
	    if (!used[Vec[v][i]])
	    {
	        dfs(Vec[v][i], min(2, rk + 1));
	    }
    }
    ans = max(ans, arr1[v]);
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    n = readInt();
    Vec.resize(n + 1);
    forn(i, n)
    {
        arr[i] = readInt();
        arr1[i] = arr[i];
        if (arr[i] > max1)
        {
            maxi = i;
            max1 = arr[i];
        }
    }
    forn(i, n - 1)
    {
	    a = readInt();
	    b = readInt();
	    Vec[a].pb(b);
	    Vec[b].pb(a);
    }
    forn(i, n) if (arr[i] == max1) sum++;
    if (sum == 1) 
    {
        dfs(maxi, 0);
        writeInt(ans);
        exit(0);
    }
    else ans = max1 + 2; 
    forn(i, n)
    {
        if (arr[i] == max1) cnt = 1;
        else cnt = 0;
        fore(j, Vec[i].size()) if (arr[Vec[i][j]] == max1) cnt++;
        if (cnt == sum) ans = max1 + 1;
    }
    writeInt(ans);

    return 0;
}