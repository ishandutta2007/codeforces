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

int t[4 * MAXN], f[4 * MAXN], dp[52][35002];

void relax(int v)
{
    t[v] = max(t[2 * v], t[2 * v + 1]);
}

void push(int v)
{
    if (f[v] > 0)
    {
        f[2 * v] += f[v];
        f[2 * v + 1] += f[v];
        t[2 * v] += f[v];
        t[2 * v + 1] += f[v];
        f[v] = 0;
    }
}

void build(int v, int l, int r, int k)
{
    if (l == r)
    {
        if (k >= 0) t[v] = dp[k][l];
        f[v] = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid, k);
    build(2 * v + 1, mid + 1, r, k);
    t[v] = max(t[2 * v], t[2 * v + 1]);
    f[v] = 0;
}

void upd(int v, int l, int r, int a, int b, int add)
{
    if (l > b || r < a)
    {
        return;
    }
    push(v);
    if (l >= a && r <= b)
    {
        t[v] += add;
        f[v] += add;
        return;
    }
    else
    {
        int mid = (l + r) / 2;
        upd(2 * v, l, mid, a, b, add);
        upd(2 * v + 1, mid + 1, r, a, b, add);
        relax(v);
    }
}

int getmax(int v, int l, int r,  int a, int b)
{
    if (r < a || l > b)
    {
        return -INF;
    }
    push(v);
    if (l >= a && r <= b)
    {
        return t[v];
    }
    else
    {
        int mid = (l + r) / 2;
        return max(getmax(2 * v, l, mid, a, b), getmax(2 * v + 1, mid + 1, r, a, b));
    }
}

int n, k, arr[MAXN], prev[MAXN], last[MAXN], ans;

_ void source()
{
    cin >> n >> k;
    forn(i, n)
    {
        cin >> arr[i];
        prev[i] = last[arr[i]];
        last[arr[i]] = i;
    }
    for (int i = 1; i <= k; i++)
    {
        build(1, 0, n, i - 1);
        for (int j = 1; j <= n; j++)
        {
            //assert(prev[j] <= j - 1);
            upd(1, 0, n, prev[j], j - 1, 1);
            dp[i][j] = getmax(1, 0, n, 0, j);
            //assert(getmax(1, 0, n, 0, j) >= dp[i][j - 1]);
            //cout << dp[i][j] << " ";
            ans = max(ans, dp[i][j]);
        }
        //cout << endl;
    }
    cout << ans;
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
    srand(time(0));
    source();
    return 0;
}