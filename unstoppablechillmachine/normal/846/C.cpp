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

ll pref[5010], n, arr[5010], ans = -BINF;
pll mx[5010], p;
_ ll sum(int l, int r)
{
    return pref[r - 1] - pref[l - 1];
}

_ void source()
{
    cin >> n;
    fore(i, n)
    {
        cin >> arr[i];
        pref[i] = arr[i];
        if (i)
        {
            pref[i] += pref[i - 1];
        }
    }
    fore(i, n + 1)
    {
        mx[i] = mk(-BINF, -BINF);
        for (int j = i; j <= n; j++)
        {
            ll a = sum(i, j) - sum(j, n);
            if (mx[i].f < a)
            {
                mx[i] = mk(a, j);
            }
        }
    }
    //cout << mx[1].f << " " << mx[1].sec << endl;
    fore(i, n + 1)
    {
        for (int j = i; j <= n; j++)
        {
            if (sum(0, i) - sum(i, j) + mx[j].f > ans)
            {
                ans = sum(0, i) - sum(i, j) + mx[j].f;
                p = mk(i, j);
            }
        }
    }
    cout << p.f << " " << p.sec << " " << mx[p.sec].sec;
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