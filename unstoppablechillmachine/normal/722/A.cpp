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
const int MAXN = 7e7;
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

int a, b, n,  ans = INF;
string s;
pii res;

int get(int a, int b)
{
    int a1 = a / 10, a2 = a % 10, a3 = b / 10, a4 = b % 10;
    int res = 0;
    if (a1 != s[0] - '0')
    {
        res++;
    }
    if (a2 != s[1] - '0')
    {
        res++;
    }
    if (a3 != s[3] - '0')
    {
        res++;
    }
    if (a4 != s[4] - '0')
    {
        res++;
    }
    return res;
}

_ void source()
{
    cin >> n >> s;
    if (n == 12)
    {
        forn(i, 12)
        {
            fore(j, 60)
            {
                if (get(i, j) < ans)
                {
                    ans = get(i, j);
                    res = mk(i, j);
                }
            }
        }
        if (res.f < 10)
        {
            cout << 0;
        }
        cout << res.f << ':';
        if (res.sec < 10)
        {
            cout << 0;
        }
        cout << res.sec;
        exit(0);
    }
    fore(i, 24)
    {
        fore(j, 60)
        {
            if (get(i, j) < ans)
            {
                ans = get(i, j);
                res = mk(i, j);
            }
        }
    }
    if (res.f < 10)
    {
        cout << 0;
    }
    cout << res.f << ':';
    if (res.sec < 10)
    {
        cout << 0;
    }
    cout << res.sec;
}

int main()
{
#ifdef EXTRATERRESTRIAL_
    //freopen("input.txt", "r", stdin);
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