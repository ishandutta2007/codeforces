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
const long long LINF = LLONG_MAX;
const long double EPS = 1e-9;
const long double PI = acos(-1);

_ void error()
{
    cout << -1;
    exit(0);
}

#define TASK ""

bool used[1010], f[3010][3010];
string s;
int n, dp[3010], from[3010];
vi arr;
bool check(char a, char b, char c)
{
    if (!used[a] && !used[b] && !used[c])
    {
        if (a == b && b == c)
        {
            return true;
        }
        return false;
    }
    return true;
}

_ void source()
{
    used[int('a')] = true;
    used[int('e')] = true;
    used[int('i')] = true;
    used[int('o')] = true;
    used[int('u')] = true;
    cin >> s;
    n = int(s.size());
    s.ins(s.begin(), ' ');
    forn(i, n)
    {
        f[i][i] = true;
        if (i < n)
        {
            f[i][i + 1] = true;
        }
    }
    for (int len = 3; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int r = i + len - 1;
            if (f[i][r - 1] && check(s[r - 2], s[r - 1], s[r]))
            {
                f[i][r] = true;
            }
        }
    }
    forn(i, n)
    {
        dp[i] = INF;
    }
    dp[1] = 1;
    dp[2] = 1;
    from[1] = 0;
    from[2] = 0;
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (f[j][i])
            {
                if (dp[j - 1] + 1 < dp[i])
                {
                    dp[i] = dp[j - 1] + 1;
                    from[i] = j - 1;
                }
            }
        }
    }
    int now = n;
    while (now)
    {
        arr.pb(now);
        now = from[now];
    }
    reverse(all(arr));
    arr.ins(arr.begin(), 0);
    for (int i = 0; i < int(arr.size()) - 1; i++)
    {
        for (int j = arr[i] + 1; j <= arr[i + 1];j++)
        {
            cout << s[j];
        }
        cout << ' ';
    }
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