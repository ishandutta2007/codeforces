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

bool check(ll a, ll b, ll c, ll d)
{
    //if (a > b) swap(a, b);
    //if (c > d) swap(c, d);
    return(c >= a && d >= b);
}

ll a, b, h, w, n, a1, h1, w1, cnt, ans = INF;
vll arr;
unordered_map<ll, ll> mp, mp1;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> a >> b >> h >> w >> n;
    if (check(a, b, h, w))
    {
        writeInt(0);
        exit(0);
    }
    forn(i, n)
    {
        cin >> a1;
        if (a1 > 1) arr.pb(a1);
    }
    sort(rall(arr));
    mp[h * 1e6 + w] = 0;
    mp[w * 1e6 + h] = 0;
    fore(i, arr.size())
    {
        a1 = arr[i];
        mp1.clear();
        for(unordered_map<ll, ll>::iterator it = mp.begin(); it != mp.end(); it++)
        {
            h1 = it -> f / 1e6;
            w1 = it -> f % MOD;
            cnt = it -> sec;
            if (!mp1[h1 * 1e6 + w1]) mp1[h1 * 1e6 + w1] = cnt;
            else mp1[h1 * 1e6 + w1] = min(mp1[h1 * 1e6 + w1], cnt);
            if (h1 < a)
            {
                if (!mp1[min(h1 * a1, a + 1) * 1e6 + w1]) mp1[min(h1 * a1, a + 1) * 1e6 + w1] = cnt + 1;
                else mp1[min(h1 * a1, a + 1) * 1e6 + w1] = min(cnt + 1, mp1[min(h1 * a1, a + 1) * 1e6 + w1]);
            }
            if (w1 < b)
            {
                if (!mp1[h1 * 1e6 + min(w1 * a1, b + 1)]) mp1[h1 * 1e6 + min(w1 * a1, b + 1)] = cnt + 1;
                else mp1[h1 * 1e6 + min(w1 * a1, b + 1)] = min(mp1[h1 * 1e6 + min(w1 * a1, b + 1)], cnt + 1);
            }
        }
        mp.clear();
        mp = mp1;
        for(unordered_map<ll, ll>::iterator it = mp.begin(); it != mp.end(); it++)
        {
            h1 = it -> f / 1e6;
            w1 = it -> f % MOD;
            cnt = it -> sec;
            //cout << h1 << " " << w1 << " " << cnt << endl;
            if (check(a, b, h1, w1)) ans = min(ans, cnt);
        }
        if (ans != INF)
        {
	    writeInt(ans);
	    exit(0);
	}
    }

    if (ans == INF) error();


    return 0;
}