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
#define chcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<int>(cout, " "))

const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int SMAXN = 1e3 + 10;
const int P = 259;
const ll BINF = 1e18 + 10;
const ld EPS = 1e-10;
const ld PI = acos(-1);

ll n, a, b, cnt, pref[MAXN], dp[5010][5010], k1, k2, rst;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> a >> b >> cnt;
    dp[0][a] = 1;
    forn(i, cnt)
    {
        pref[0] = 0;
        forn(j, n) pref[j] = (pref[j - 1] + (dp[i - 1][j] % MOD)) % MOD;
        //cout << pref[n] << endl;
        forn(j, n)
        {
            if (abs(j - b) % 2 == 0) k1 = (abs(j - b)) / 2 - 1;
            else k1 = (abs(j - b)) / 2;
            if (j == b) continue;
            else if (j < b) dp[i][j] = (pref[j - 1] + pref[j + k1] - pref[j] + 10 * MOD) % MOD;
            else dp[i][j] = (pref[n] - pref[j] + pref[j - 1] - pref[j - k1 - 1] + 10 * MOD) % MOD;
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }

    pref[0] = 0;
    forn(j, n) pref[j] = (pref[j - 1] + dp[cnt][j]) % MOD;
    cout << pref[n];

    return 0;
}