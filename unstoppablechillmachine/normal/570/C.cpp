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

#define _ inline
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
#define pw(x) (1 << (x))
#define sqr(x) ((x) * (x))
#define fro for
#define itn int
#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)
#define chcpy(Vec) copy(Vec.begin(), Vec.end(), ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(), ostream_iterator<int>(cout, " "))
#define endl "\n"
#define right rightt
#define left leftt
#define prev prevv
#define next nextt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int LOG = 20;
const int P = 239017;
const long long BINF = 1e18 + 10;
const long long LINF = LLONG_MAX;
const long double EPS = 1e-9;
const long double PI = acos(-1);

_ void error()
{
    cout << -1;
    exit(0);
}

#define TASK "printing"

int n, m, cur, ans, pos;
string s;
char ch;

bool check(int pos, char ch)
{
    if (ch == '.')
    {
        return s[pos] == '.';
    }
    return s[pos] >= 'a' && s[pos] <= 'z';
}

_ void source()
{
    cin >> n >> m;
    cin >> s;
    s.ins(s.begin(), ' ');
    s += " ";
    forn(i, n)
    {
        if (s[i] == '.')
        {
            cur++;
        }
        else
        {
            ans += max(ll(0), cur - 1);
            cur = 0;
        }
    }
    ans += max(ll(0), cur - 1);
    forn(i, m)
    {
        cin >> pos >> ch;
        if (check(pos, ch))
        {
            cout << ans << endl;
            s[pos] = ch;
            continue;
        }
        if (ch == '.')
        {
            int cnt = 0;
            cnt += s[pos - 1] == '.';
            cnt += s[pos + 1] == '.';
            ans += cnt;
            cout << ans << endl;
        }
        else
        {
            int cnt = 0;
            cnt += s[pos - 1] == '.';
            cnt += s[pos + 1] == '.';
            ans -= cnt;
            cout << ans << endl;
        }
        s[pos] = ch;
    }
}

signed main()
{
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
    srand(time(0));
    source();
    return 0;
}