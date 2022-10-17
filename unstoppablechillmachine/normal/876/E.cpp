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
const long double EPS = 1e-6;
const long double PI = acos(-1);

#define TASK ""

int m, n, cnt;
bool used[MAXN];
vvi g;
pair<int, int> dp[MAXN];
vector<int> ans;
vvi arr;
void dfs(int v)
{
    used[v] = true;
    pair<int, int> cur_min = mk(2, m + 1);
    for (auto u : g[v])
    {
        if (!used[u])
        {
            dfs(u);
        }
        cur_min = min(cur_min, dp[u]);
    }
    if (mk(ll(2), v) < cur_min)
    {
        dp[v] = {2, v};
    }
    else if (mk(ll(1), v) < cur_min)
    {
        dp[v] = {1, v};
        ans.pb(v);
    }
    else
    {
        cout << "No";
        exit(0);
    }
}

_ void source()
{
    cin >> n >> m;
    arr.rsz(n + 1);
    g.rsz(m + 1);
    forn(i, n)
    {
        cin >> cnt;
        arr[i].rsz(cnt);
        for (int j = 0; j < cnt; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 2; i <= n; i++)
    {
        int j = 0;
        while (j < arr[i].size() && j < arr[i - 1].size() && arr[i][j] == arr[i - 1][j])
        {
            j++;
        }
        if (j >= arr[i].size() && j >= arr[i - 1].size())
        {
            continue;
        }
        else if (j >= arr[i].size())
        {
            cout << "No";
            exit(0);
        }
        else if (j < arr[i - 1].size())
        {
            g[arr[i - 1][j]].pb(arr[i][j]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        //cout << g[i].size() << endl;
        if (!used[i])
        {
            dfs(i);
        }
    }
    cout << "Yes" << endl << ans.size() << endl;
    for (auto it : ans)
    {
        cout << it << " ";
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