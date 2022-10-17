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
#define fro for
#define itn int
#define forn(i, n) for (int i(1); i <= n; i++)
#define fore(i, n) for (int i(0); i < n; i++)
#define chcpy(Vec) copy(Vec.begin(), Vec.end(), ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(), ostream_iterator<int>(cout, " "))

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int SMAXN = 1e3 + 10;
const int P = 259;
const ll BINF = 1e18 + 10;
const ld EPS = 1e-10;
const ld PI = acos(-1);

inline void error()
{
    cout << -1;
    exit(0);
}

int tr[4 * MAXN], h[MAXN], f[MAXN], s;
bool used[MAXN];
vi arr;
vvi Vec;
void dfs(int v, int cnt = 1)
{
    used[v] = true;
    h[v] = cnt;
    arr.pb(v);
    fore(i, Vec[v].size())
    {
        if (!used[Vec[v][i]])
        {
            dfs(Vec[v][i], cnt + 1);
            arr.pb(v);
        }
    }
}

void relax(int a)
{
    //tr[a] = min(tr[2 * a], tr[2 * a + 1]);
    if (h[tr[2 * a]] < h[tr[2 * a + 1]])
    {
        tr[a] = tr[2 * a];
    }
    else
    {
        tr[a] = tr[2 * a + 1];
    }
}

void upd(int a)
{
    while (a)
    {
        a /= 2;
        relax(a);
    }
}

int getmin(int l, int r)
{
    int res = INF, v;
    if (l > r)
    {
        swap(l, r);
    }
    while (l <= r)
    {
        if (l % 2 == 1)
        {
            if (h[tr[l]] < res)
            {
                res = h[tr[l]];
                v = tr[l];
            }
            l++;
        }
        if (r % 2 == 0)
        {
            if (h[tr[r]] < res)
            {
                res = h[tr[r]];
                v = tr[r];
            }
            r--;
        }
        l /= 2;
        r /= 2;
    }
    return v;
}

int get(int a, int b, int c)
{
    int sum = 0;
    int d = getmin(f[a] + s - 1, f[c] + s - 1);
    int e = getmin(f[b] + s - 1, f[c] + s - 1);
    if ((d == c && d != e) || (e == c && d != e))
    {
        return 1;
    }
    else if (d == c && e == c)
    {
        if (h[getmin(f[b] + s - 1, f[a] + s - 1)] < h[c])
        {
            return 1;
        }
        else
        {
            //cout << c << endl;
            return h[getmin(f[a] + s - 1, f[b] + s - 1)] - h[c] + 1;
        }
    }

    if (d == e && h[getmin(f[b] + s - 1, f[a] + s - 1)] > h[d])
    {
        sum += h[getmin(f[b] + s - 1, f[a] + s - 1)] - h[d];
        sum += h[c] - h[d] + 1;
        return sum;
    }
    else
    {
        return min(abs(h[e] - h[c]), abs(h[c] - h[d])) + 1;
    }
}

int n, m, a, b, c, d, k;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    Vec.resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> a;
        Vec[a].pb(i);
        Vec[i].pb(a);
    }
    dfs(1);
    int m = int(arr.size());
    s = 1 << (32 - __builtin_clz(m));
    forn(i, m)
    {
        tr[s + i - 1] = arr[i - 1];
        upd(s + i - 1);
    }

    fore(i, m)
    {
        int v = arr[i];
        if (!f[v])
        {
            f[v] = i + 1;
        }
    }
    forn(i, k)
    {
        cin >> a >> b >> c;
        int ans  = -INF;
        ans = max(ans, get(a, b, c));
        ans = max(ans, get(a, c, b));
        ans = max(ans, get(b, c, a));
        cout << ans << endl;
    }

    return 0;
}