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

ll ans = BINF, x, y;
int c[MAXN], n, arr2[MAXN];
vi arr;
vector<bool> p(1e6 + 1, true);
_ void fact(int n)
{
    if (!p[n])
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            bool t = false;
            while (n % i == 0)
            {
                t = true;
                n /= i;
            }
            c[i] += t;
            if (p[n])
            {
                break;
            }
        }
    }
    if (n > 1)
    {
        c[n]++;
    }
}

bool cmp(int a, int b)
{
    return c[a] > c[b] || (c[a] == c[b] && a < b);
}

_ void source()
{
    p[0] = p[1] = false;
    for (int i = 2; i <= 1e6; i++)
    {
        if (p[i] && ll(i) * ll(i) <= 1e6)
        {
            for (int j = i * i; j <= 1e6; j += i)
            {
                p[j] = false;
            }
        }
    }
    cin >> n >> x >> y;
    ll k = min(x, y);
    forn(i, n)
    {
        cin >> arr2[i];
        fact(arr2[i]);
    }
    arr.pb(2);
    for (int i = 3; i <= 1e6; i += 2)
    {
        if (p[i] && c[i])
        {
            arr.pb(i);
        }
    }
    sort(all(arr), cmp);
    int lim = arr.size();
    for (int i = 0; i < lim; i++)
    {
        if (ll(n - c[arr[i]]) * k >= ans)
        {
            break;
        }
        ll sum = 0;
        for (int j = 1; j <= n; j++)
        {
            if (arr2[j] % arr[i]) sum += min(x, y * ll(arr[i] - arr2[j] % arr[i]));
        }
        ans = min(ans, sum);
    }
    cout << min(ans, ll(k) * ll(n));
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