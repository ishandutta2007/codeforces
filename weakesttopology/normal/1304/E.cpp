#include "bits/stdc++.h"

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp(x, y) make_pair(x, y)
#define ALL(X) X.begin(), X.end()
#define READ(X) for (int i = 0; i < (int)X.size(); ++i) cin >> X[i];
#define SZ(X) (int)X.size()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int N = 2 * 1e5;
int st[2 * N];
int M;

int n;
vvi E;
vi euler, f, h;

void build()
{
    for (int i = M - 1; i > 0; --i)
        st[i] = h[st[i << 1]] <= h[st[i << 1 | 1]] ? st[i << 1] : st[i << 1 | 1];
}

int query(int l, int r)
{
    int res = -1;
    for (l += M, r += M + 1; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
        {
            res = (res == -1 || h[res] > h[st[l]]) ? st[l] : res;
            ++l;
        }
        if (r & 1)
        {
            --r;
            res = (res == -1 || h[res] > h[st[r]]) ? st[r] : res;
        }
    }
    return res;
}

void dfs(int u)
{
    f[u] = euler.size();
    euler.pb(u);

    for (auto v : E[u])
    {
        if (f[v] != INF)
            continue;

        h[v] = h[u] + 1;
        dfs(v);
        euler.pb(u);
    }
}

void preprocess(int root)
{
    f.assign(n, INF);
    h.assign(n, 0);
    euler.clear();

    dfs(root);
    M = euler.size();
    for (int i = 0; i < M; ++i)
        st[M + i] = euler[i];

    build();
}

int LCA(int u, int v)
{
    return query(min(f[u], f[v]), max(f[u], f[v]));
}

int dist(int u, int v)
{
    int w = LCA(u, v);
    return abs(h[u] - h[w]) + abs(h[w] - h[v]);
}

int main()
{ _
    cin >> n;
    E.assign(n, vi());
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v; --u; --v;
        E[u].pb(v);
        E[v].pb(u);
    }
    preprocess(0);

    int q; cin >> q;
    while (q--)
    {
        int x, y, a, b, k; cin >> x >> y >> a >> b >> k;

        x--; y--; a--; b--;

        bool ans = false;

        if (dist(a, b) <= k && dist(a, b) % 2 == k % 2)
            ans = true;

        if (dist(a, x) + 1 + dist(y, b) <= k && dist(y, b) % 2 == (k - dist(a, x) - 1) % 2)
            ans = true;

        swap(x, y);
        if (dist(a, x) + 1 + dist(y, b) <= k && dist(y, b) % 2 == (k - dist(a, x) - 1) % 2)
            ans = true;

        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    exit(0);
}

/*
 * INT_MAX ~ 2 * 1e9 ~ 2^31 - 1
 * LLONG_MAX ~ 9 * 1e18 ~ 2^63 - 1
 * ULLONG_MAX ~ 18 * 1e18 ~ 2^64 - 1
 *
 * INF ~ 1e9
 * LINF ~ 4.5 * 1e18
 *
 * CHECK:
 *      OVERFLOW
 *      IF/LOOP CONDITIONS
 *      CREATION OF STL CONTAINERS
*/