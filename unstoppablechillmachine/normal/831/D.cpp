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
const int MAXN = 2e7 + 10;
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

ll n, k, a, dp[5010][5010], arr[5010], arr2[5010];
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> a;
    forn(i, n)
    {
        cin >> arr[i];
    }
    forn(i, k)
    {
        cin >> arr2[i];
    }
    sort(arr + 1, arr + n + 1);
    sort(arr2 + 1, arr2 + k + 1);
    forn(i, 5000)
    {
        fore(j, 5000)
        {
            dp[i][j] = BINF;
        }
    }

    //dp[0][0] = 0;
    forn(i, n)
    {
        forn(j, k)
        {
            dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            dp[i][j] = min(dp[i][j], max(dp[i - 1][j - 1], abs(arr[i] - arr2[j]) + abs(arr2[j] - a)));
        }
    }

    cout << dp[n][k];
    return 0;
}