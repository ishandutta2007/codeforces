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
//#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)
#define chcpy(Vec) copy(Vec.begin(), Vec.end(), ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(), ostream_iterator<int>(cout, " "))
//#define endl "\n"
#define right rightt
#define left leftt
#define prev prevv
#define next nextt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int LOG = 30;
const int P = 239017;
const long long BINF = 1e18 + 10;
const long long LINF = LLONG_MAX;
const long double EPS = 1e-6;
const long double PI = acos(-1);

#define TASK ""

int t[8 * MAXN], now[200010];
bool ff[8 * MAXN];
vector<int> arr;
vvi g;
void dfs(int v)
{
    arr.pb(v);
    for (auto u : g[v])
    {
        dfs(u);
    }
    arr.pb(v);
}

void relax(int v, int l, int r)
{
    t[v] = 0;
    int mid = (l + r) / 2;
    t[v] = t[2 * v] + t[2 * v + 1];
}

void push(int v, int len1, int len2)
{
    if (ff[v])
    {
        ff[2 * v] ^= ff[v];
        ff[2 * v + 1] ^= ff[v];
        t[2 * v] = len1 - t[2 * v];
        t[2 * v + 1] = len2 - t[2 * v + 1];
        ff[v] = 0;
    }
}

void build(int v, int l, int r)
{
    if (l == r)
    {
        if (l <= arr.size()) t[v] = now[arr[l - 1]];
        else t[v] = 0;
        ff[v] = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
    t[v] = t[2 * v] + t[2 * v + 1];
    ff[v] = 0;
}

void upd(int v, int l, int r, int a, int b)
{
    if (l > b || r < a)
    {
        return;
    }
    int md = (l + r) / 2;
    push(v, md - l + 1, r - md);
    if (l >= a && r <= b)
    {
        ff[v] ^= 1;
        //cout << v << " " << ff[v] << endl;
        t[v] = r - l + 1 - t[v];
        return;
    }
    else
    {
        int mid = (l + r) / 2;
        upd(2 * v, l, mid, a, b);
        upd(2 * v + 1, mid + 1, r, a, b);
        relax(v, l, r);
    }
}

int getsum(int v, int l, int r,  int a, int b)
{
    if (r < a || l > b)
    {
        return 0;
    }
    int md = (l + r) / 2;
    push(v, md - l + 1, r - md);
    if (l >= a && r <= b)
    {
        //cout << v << ' ' << t[v] << ' ' << ff[v] << endl;
        return t[v];
    }
    else
    {
        int mid = (l + r) / 2;
        return getsum(2 * v, l, mid, a, b) + getsum(2 * v + 1, mid + 1, r, a, b);
    }
}

int n, a, f[200010], e[200010], q;
string s;
_ void source()
{
    int h = 2e6;
    cin >> n;
    g.rsz(n + 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> a;
        g[a].pb(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> now[i];
    }
    dfs(1);
    int m = arr.size();
    for (int i = 0; i < m; i++)
    {
        //cout << arr[i] << " ";
        a = arr[i];
        if (!f[a])
        {
            f[a] = i + 1;
        }
        else
        {
            e[a] = i + 1;
        }
    }
    build(1, 1, h);
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> s;
        if (s == "get")
        {
            cin >> a;
            cout << getsum(1, 1, h, f[a], e[a]) / 2 << endl;
        }
        else
        {
            cin >> a;
            upd(1, 1, h, f[a], e[a]);
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