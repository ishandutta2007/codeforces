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
#define chcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<int>(cout, " "))

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int SMAXN = 1e3 + 10;
const int P = 259;
const ll BINF = 1e18 + 10;
const ld EPS = 1e-9;
const ld PI = acos(-1);

string s1, s2;
int n, m, cnt, dp[SMAXN][SMAXN][11][2], dp1[SMAXN][SMAXN][11], ans;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> m >> cnt;
    cin >> s1 >> s2;
    s1.ins(s1.begin(), '.');
    s2.ins(s2.begin(), '.');
    forn(i, n)
    forn(j, m)
    forn(k, cnt)
    {
        dp[i][j][k][0] = max(dp1[i - 1][j][k], dp1[i][j - 1][k]);
        if (s1[i] == s2[j]) dp[i][j][k][1] = max(dp[i - 1][j - 1][k][1] + 1, dp1[i - 1][j - 1][k - 1] + 1);
        //dp[i][j][k][1] = max(dp[i][j][k][1], dp[i][j - 1][k][1]);
        dp1[i][j][k] = max(dp[i][j][k][0], dp[i][j][k][1]);
        ans = max(ans, dp1[i][j][k]);
        //cout << i << ' ' << j << ' ' << k << ' ' << dp1[i][j][k] << endl;
    }
    cout << ans;
    return 0;
}