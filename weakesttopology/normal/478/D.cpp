#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define mp(x, y) make_pair(x, y)
#define ALL(X) X.begin(), X.end()
#define READ(X) for (int i = 0; i < (int)X.size(); ++i) cin >> X[i];

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const ll MOD = 1e9 + 7;

map<vi, ll> H;

int main()
{ _
    int r, g; cin >> r >> g;

    int h = 0;
    while (((h + 1) * (h + 2)) / 2 <= r + g)
        h++;

    bool x = 0;
    vi dp[2] = { vi(r + 1, 0), vi(r + 1, 0) };
    dp[0][0] = g > 0;
    dp[0][1] = r > 0;
    for (int i = 2; i <= h; ++i)
    {
        dp[!x].assign(r + 1, 0);
        for (int j = 0; j < r + 1; ++j)
            dp[!x][j] = dp[x][j] * ((i * (i + 1)) / 2 <= j + g);
        for (int j = i; j < r + 1; ++j)
            dp[!x][j] = (dp[!x][j] + dp[x][j - i] * (((i - 1) * i) / 2 <= j - i + g)) % MOD;
        x = !x;
    }
    ll sum = 0;
    for (int i = 0; i < r + 1; ++i)
        sum = (sum + dp[x][i]) % MOD;

    cout << sum << endl;

    exit(0);
}