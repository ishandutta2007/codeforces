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
//#define endl "\n"

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
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

int n, m, k, a, b, cost, ans = INF, dp[82][82][82][82];
vector<vpii> g;

_ void source()
{
    cin >> n >> k;
    g.rsz(n + 1);
    cin >> m;
    forn(i, m)
    {
        cin >> a >> b >> cost;
        g[a].pb(mk(b, cost));
    }
    for (int i = 1; i <= k; i++)
    {
        for (int l = 0; l <= n + 1; l++)
        {
            for (int r = 0; r <= n + 1; r++)
            {
                for (int now = l + 1; now < r; now++)
                {
                    dp[i][l][r][now] = INF;
                }
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int l = 0; l <= n + 1; l++)
        {
            for (int r = l; r <= n + 1; r++)
            {
                for (int now = l + 1; now < r; now++)
                {
                    for (auto v : g[now])
                    {
                        if (v.f > l && v.f < r && v.f != now)
                        {
                            if (now > v.f)
                            {
                                dp[i + 1][l][now][v.f] = min(dp[i + 1][l][now][v.f], dp[i][l][r][now] + v.sec);
                            }
                            else
                            {
                                dp[i + 1][now][r][v.f] = min(dp[i + 1][now][r][v.f], dp[i][l][r][now] + v.sec);
                            }
                        }
                    }
                }
            }
        }
    }

    for (int l = 0; l <= n + 1; l++)
    {
        for (int r = 0; r <= n + 1; r++)
        {
            for (int now = l + 1; now < r; now++)
            {
                ans = min(ans, dp[k - 1][l][r][now]);
            }
        }
    }
    if (ans < INF)
    {
        cout << ans;
    }
    else 
    {
        cout << -1;
    }
}

int main()
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