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

vi t[4 * MAXN];
int l2, r2, n, m, s, a, l, r, res1, res2, res3;
ll pref[10];
_ void relax(int v)
{
    int n1 = int(t[2 * v].size()), n2 = int(t[2 * v + 1].size());
    int j = 0, jj = 0, n = n1 + n2;
    t[v].clear();
    for (int i = 0; i < n; i++)
    {
        if (j == n1)
        {
            t[v].pb(t[2 * v + 1][jj]);
            jj++;
        }
        else if (jj == n2)
        {
            t[v].pb(t[2 * v][j]);
            j++;
        }
        else if (t[2 * v][j] < t[2 * v + 1][jj])
        {
            t[v].pb(t[2 * v][j]);
            j++;
        }
        else
        {
            t[v].pb(t[2 * v + 1][jj]);
            jj++;
        }
    }
}

_ void upd(int a)
{
    while (a)
    {
        a >>= 1;
        relax(a);
    }
}

_ void get(int l, int r, int l2, int r2)
{
    res1 = 0;
    res2 = 0;
    res3 = 0;
    while (l <= r)
    {
        if (l & 1)
        {
            auto it1 = upper_bound(all(t[l]), l2 - 1), it2 = upper_bound(all(t[l]), r2);
            res1 += it1 - t[l].begin();
            res2 += it2 - it1;
            res3 += t[l].end() - it2;
            l++;
        }
        if (!(r & 1))
        {
            auto it1 = upper_bound(all(t[r]), l2 - 1), it2 = upper_bound(all(t[r]), r2);
            res1 += it1 - t[r].begin();
            res2 += it2 - it1;
            res3 += t[r].end() - it2;
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
}

_ void source()
{
    scanf("%d%d", &n, &m);
    s = 1 << (32 - __builtin_clz(n));
    forn(i, n)
    {
        scanf("%d", &a);
        t[i + s - 1].pb(a);
    }
    for (int i = s - 1; i > 0; i--)
    {
        relax(i);
    }
    forn(i, m)
    {
        scanf("%d%d%d%d", &l, &r, &l2, &r2);
        ll k[10];
        get(s, s + l - 2, r, r2);
        k[1] = res1;
        k[2] = res2;
        k[3] = res3;
        get(s + l - 1, s + l2 - 1, r, r2);
        k[4] = res1;
        k[5] = res2;
        k[6] = res3;
        get(s + l2, s + n - 1, r, r2);
        k[7] = res1;
        k[8] = res2;
        k[9] = res3;
        forn(j, 9)
        {
            pref[j] = pref[j - 1] + k[j];
        }
        cout << k[1] * (pref[9] - pref[4] - k[7]) + k[2] * (pref[9] - pref[3])
        + k[3] * (pref[8] - pref[3] - k[6]) + k[4] * (pref[9] - pref[4] - k[7]) + k[5] * (pref[9] - pref[5])
        + k[6] * (k[7] + k[8]) + k[5] * (k[5] - 1) / 2 << endl;
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