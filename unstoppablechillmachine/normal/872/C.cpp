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
const int MOD = 1e3 + 10;
const int MAXN = 1e6 + 10;
const int LOG = 20;
const int P = 239017;
const long long BINF = 1e18 + 10;
const long long LINF = LLONG_MAX;
const long double EPS = 1e-6;
const long double PI = acos(-1);

_ void error()
{
    cout << -1;
    exit(0);
}

#define TASK "forest"

int dp[MAXN];

_ void source()
{
    dp[0] = 0;
    forn(i, 15)
    {
        dp[i] = -INF;
        if (i >= 4)
        {
            dp[i] = max(dp[i - 4] + 1, dp[i]);
        }
        if (i >= 6)
        {
            dp[i] = max(dp[i - 6] + 1, dp[i]);
        }
        if (i >= 9)
        {
            dp[i] = max(dp[i - 9] + 1, dp[i]);
        }
        if (i >= 15)
        {
            dp[i] = max(dp[i - 15] + 1, dp[i]);
        }
        if (i >= 21)
        {
            dp[i] = max(dp[i - 21] + 1, dp[i]);
        }
        if (i >= 25)
        {
            dp[i] = max(dp[i - 25] + 1, dp[i]);
        }
        //cout << max(dp[i], ll(-1)) << endl;
    }
    int q, a;
    cin >> q;
    forn(i, q)
    {
        int ans2 = 0;
        cin >> a;
        if (a <= 15)
        {
            ans2 = dp[a];
        }
        else
        {
            if (a % 2)
            {
                ans2++;
                a -= 9;
                if (a % 4 == 0)
                {
                    ans2 += a / 4;
                }
                else
                {
                    ans2 += 1 + (a - 6) / 4;
                }
            }
            else
            {
                if (a % 4 == 0)
                {
                    ans2 += a / 4;
                }
                else
                {
                    ans2 += 1 + (a - 6) / 4;
                }
            }
        }
        if (ans2 < 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans2 << endl;
        }
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