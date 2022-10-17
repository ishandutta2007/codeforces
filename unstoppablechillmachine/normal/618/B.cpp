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
int n, m, ans[MAXN], ar[110][110];
vvi g;
bool used[MAXN];
vector<int> arr;
void dfs(int v)
{
    for (auto u : g[v])
    {
        if (!used[u])
        {
            used[u] = true;
            dfs(u);
        }
    }
    arr.pb(v);
}

_ void source()
{
    cin >> n;
    g.rsz(n + 1);
    forn(i, n)
    {
        forn(j, n)
        {
            cin >> ar[i][j];
        }
    }
    forn(i, n)
    {
        forn(j1, n)
        {
            forn(j2, n)
            {
                if (ar[i][j1] == 0 || ar[i][j2] == 0)
                {
                    continue;
                }
                if (ar[i][j1] < ar[i][j2])
                {
                    g[j1].pb(i);
                    g[j1].pb(j2);
                }
            }
        }
    }
    forn(i, n)
    {
        if (!used[i])
        {
            used[i] = true;
            dfs(i);
        }
    }
    reverse(all(arr));
    fore(i, arr.size())
    {
        ans[arr[i]] = i + 1;
    }
    forn(i, n)
    {
        cout << ans[i] << " ";
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