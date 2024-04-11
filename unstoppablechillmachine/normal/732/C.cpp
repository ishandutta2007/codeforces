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
const int MAXN = 8.2e6 + 10;
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

int a, b, c, mx, arr[4], ans = LINF;

_ void source()
{
    cin >> a >> b >> c;
    if (!a && !c && b == 1)
    {
        cout << 0;
        exit(0);
    }
    mx = max(a, max(b, c));
    for (int x = mx - 2; x <= mx + 2; x++)
    {
        if (x < 0)
        {
            continue;
        }
        for (int suf = 0; suf <= 2; suf++)
        {
            for (int pref = 0; pref <= 2; pref++)
            {
                arr[1] = arr[2] = arr[3] = x;
                for (int i = 1; i <= pref; i++)
                {
                    arr[i]++;
                }
                for (int i = 3 - suf + 1; i <= 3; i++)
                {
                    arr[i]++;
                }
                if (arr[1] < a || arr[2] < b || arr[3] < c)
                {
                    continue;
                }
                ans = min(ans, arr[1] - a + arr[2] - b + arr[3] - c);
            }
        }
    }
    cout << ans;
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