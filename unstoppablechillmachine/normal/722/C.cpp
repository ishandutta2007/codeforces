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
const long long BINF = 1e18 + 10;
const long long LINF = 1e18 + 10;
const long double EPS = 1e-10;
const long double PI = acos(-1);

_ void error()
{
    cout << -1;
    exit(0);
}

#define TASK ""

struct st
{
    ll pref, suf, mx, sum;
};

st t[4 * MAXN];
ll n, arr[MAXN], s, a;

void relax(int v)
{
    t[v].sum = t[2 * v].sum + t[2 * v + 1].sum;
    t[v].pref = max(t[2 * v].pref, t[2 * v].sum + t[2 * v + 1].pref);
    t[v].suf = max(t[2 * v + 1].suf, t[2 * v].suf + t[2 * v + 1].sum);
    t[v].mx = max(t[2 * v].mx, t[2 * v + 1].mx);
    t[v].mx = max(t[v].mx, t[2 * v].suf + t[2 * v + 1].pref);
}

void upd(int a)
{
    while (a)
    {
        a /= 2;
        relax(a);
    }
}

_ void source()
{
    cin >> n;
    s = 1 << (32 - __builtin_clz(n));
    forn(i, n)
    {
        cin >> a;
        t[s + i - 1].sum = a;
        t[s + i - 1].pref = a;
        t[s + i - 1].suf = a;
        t[s + i - 1].mx = a;
        upd(s + i - 1);
    }
    forn(i, n)
    {
        cin >> a;
        t[s + a - 1].sum = -9e13;
        t[s + a - 1].pref = -9e13;
        t[s + a - 1].suf = -9e13;
        t[s + a - 1].mx = -9e13;
        upd(s + a - 1);
        cout << max(ll(0), t[1].mx) << endl;
    }
}

int main()
{
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin
    //freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(0);
    source();
    return 0;
}