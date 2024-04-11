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

ll p_pow[MAXN], fact[MAXN], ans = 1;
int n, m, cnt, a, res;
int mp[MAXN];
bool cl[MAXN], used[MAXN];
vector<int> now, now2;
unordered_map<ll, int> g;
vector<pair<int, int> > arr[MAXN];
_ void source()
{
    p_pow[0] = 1;
    fact[0] = 1;
    forn(i, 1000000)
    {
        p_pow[i] = p_pow[i - 1] * P;
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    cin >> n >> m;
    forn(i, n)
    {
        cin >> cnt;
        now.clear();
        forn(j, cnt)
        {
            cin >> a;
            if (cl[a])
            {
                mp[a] = 1;
                cl[a] = false;
            }
            else
            {
                mp[a]++;
            }
            now.pb(a);
            now2.pb(a);
        }
        for (auto it : now)
        {
            if (cl[it])
            {
                continue;
            }
            cl[it] = true;
            arr[it].pb(mk(i, mp[it]));
        }
    }
    //cout << now2.size() << endl;
    fore(i, now2.size())
    {
        if (used[now2[i]])
        {
            continue;
        }
        res++;
        used[now2[i]] = true;
        int a = now2[i];
        //cout << a << " " << arr[a].size() << endl;
        ll cur = 0;
        fore(j, arr[a].size())
        {
            cur += p_pow[arr[a][j].f] * arr[a][j].sec;
        }
        g[cur]++;
    }
    g[0] += m - res;
    for (auto it : g)
    {
        //cout << it.f << " " << it.sec << endl;
        ans = (ans * fact[it.sec]) % MOD;
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