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
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)
#define chcpy(Vec) copy(Vec.begin(), Vec.end(), ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(), ostream_iterator<int>(cout, " "))

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const long long BINF = 1e18 + 10;
const long double EPS = 1e-9;
const long double PI = acos(-1);

inline void error()
{
    cout << -1;
    exit(0);
}

bool used[MAXN];
vvll g;
ll cnt[MAXN], n, a, b, sum, k, kol[MAXN];
ld ans;
void dfs(int v, int h, ld ver)
{
    used[v] = true;
    cnt[v] = h;
    fore(i, g[v].size())
    {
        if (!used[g[v][i]])
        {
            kol[v]++;
        }
    }
    fore(i, g[v].size())
    {
        if (!used[g[v][i]])
        {
            dfs(g[v][i], h + 1, ld(ver / ld(kol[v])));
        }
    }
    if (kol[v] == 0)
    {
        ans += ld(h) * ver;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0));
    cin >> n;
    if (n == 1)
    {
        cout << 0.00000000;
        exit(0);
    }
    if (n == 2)
    {
        cout << 1.00000000;
        exit(0);
    }
    g.rsz(n + 1);
    forn(i, n - 1)
    {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1, 0, 1);
    cout << fixed << setprecision(10) << ans;
    return 0;
}