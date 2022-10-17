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
#define sz size
#define rsz resize
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
const ld EPS = 1e-10;
const ld PI = acos(-1);

inline int readChar();
template <class T> inline T readInt();
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

map<string, multiset<int> > mp;
multiset<int> st, st1;
int n, len, a, ans, max1, res, a1, a2;
string s, s2;
multiset<int>::iterator it1, it2, it, it11, it22;
vector<pair<string, pii> > arr;
int main()
{
    //freopen("lift.in","r",stdin);
    //freopen("lift.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> len;
    forn(i, n)
    {
        cin >> s >> a;
        mp[s].ins(a);
        //cout << mp[s].sz() << endl;
    }
    //cout << mp["a"].sz() << endl;
    for(auto i : mp)
    {
        s = i.f;
        s2 = s;
        st = i.sec;
        if (st.empty()) continue;
        //cout << s2 << endl;
        
        reverse(all(s));
        
        if (s != s2)
        {
            st1 = mp[s];
            if (st1.empty()) continue;
            a1 = st.size();
            a2 = st1.size();
            forn(j, min(a1, a2))
            {
                it1 = st.end();
                it2 = st1.end();
                it1--;
                it2--;
                if (*it1 + *it2 > 0)
                {
                    ans += (*it1 + *it2);
                    arr.pb(mk(s, mk(*it1, *it2)));
                    st.ers(it1);
                    st1.ers(it2);
                }
                else break;
            }
            mp[s2] = st;
            mp[s] = st1;
        }
        else
        {
            //cout << st.size() << endl;
            a = st.size();
            forn(j, a / 2)
            {
                //cout << j << endl;
                it1 = st.end();
                it1--;
                it2 = it1;
                it2--;
                if (*it1 + *it2 > 0)
                {
                    ans += (*it1 + *it2);
                    arr.pb(mk(s, mk(*it1, *it2)));
                    st.ers(it1);
                    it2 = st.end();
                    it2--;
                    st.ers(it2);
                }
                else break;
            }
            mp[s] = st;
        }
    }
    
    //cout << ans << endl;

    for(auto i : mp)
    {
        s = i.f;
        st = i.sec;
        if (st.empty()) continue;
        it1 = st.end();
        it1--;
        s2 = s;
        reverse(all(s));
        if (s == s2)
        {
            max1 = max(max1, *it1);
        }
    }

    fore(i, arr.size())
    {
        s = arr[i].f;
        a1 = arr[i].sec.f;
        a2 = arr[i].sec.sec;
        if (a1 > a2) swap(a1, a2);
        s2 = s;
        reverse(all(s));
        if (s == s2)
        {
            res = max(res, -a1);
        }
    }

    cout << ans + max(res, max1);


    return 0;
}