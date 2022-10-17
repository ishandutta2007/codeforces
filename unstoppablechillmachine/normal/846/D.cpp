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

struct st
{
    int f, sec, t;
};

int n, m, k, cnt, f[510][510], dp[510][510], p1[510][510], p2[510][510];
vector<st> arr;
bool cmp(st a, st b)
{
    return a.t < b.t;
}

bool check(int v)
{
    if (v > cnt)
    {
        return false;
    }
    forn(i, n)
    {
        forn(j, m)
        {
            f[i][j] = 0;
            dp[i][j] = 0;
        }
    }
    int j = 1;
    while (j <= cnt && arr[j].t <= arr[v].t)
    {
        f[arr[j].f][arr[j].sec] = 1;
        j++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            if (f[i][j])
            {
                p1[i][j] = p1[i][j - 1] + 1;
            }
            else
            {
                p1[i][j] = 0;
            }
        }
    }
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (f[i][j])
            {
                p2[i][j] = p2[i - 1][j] + 1;
            }
            else
            {
                p2[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = min(min(p1[i][j], p2[i][j]), dp[i - 1][j - 1] + 1);
            if (dp[i][j] >= k)
            {
                return true;
            }
        }
    }
    return false;
}

_ void source()
{
    cin >> n >> m >> k >> cnt;
    arr.rsz(cnt);
    fore(i, cnt)
    {
        cin >> arr[i].f >> arr[i].sec >> arr[i].t;
    }
    sort(all(arr), cmp);
    arr.ins(arr.begin(), {1, 1, 1});
    int l = 0, r = cnt + 1;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    if (l < cnt && check(l + 1))
    {
        cout << arr[l + 1].t;
    }
    else
    {
        cout << -1;
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