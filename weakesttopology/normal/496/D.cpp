#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n'
#define mp(x, y) make_pair(x, y)
#define ALL(X) X.begin(), X.end()
#define READ(X) for (int i_ = 0; i_ < (int)X.size(); ++i_) cin >> X[i_]
#define SZ(X) (int)X.size()

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

int end_index(int t, int x, const vvi& sum)
{
    int n = SZ(sum[0]);

    int prev[2] = { x ? sum[0][x - 1] : 0, x ? sum[1][x - 1] : 0 };

    int b = x - 1;
    for (int z = n - 1 - b; z; z >>= 1)
        while (b + z < n && max(sum[0][b + z] - prev[0], sum[1][b + z] - prev[1]) < t)
            b += z;
    ++b;

    return b;
}

int sets(int t, const vi& a, const vvi& sum)
{
    int n = SZ(sum[0]), s = 0;

    int wins[2] = { 0 };

    int last = 0;
    for (int x = 0; x != n; last = a[x] % 2, ++x, ++s)
    {
        x = end_index(t, x, sum);
        if (x == n)
        {
            s = -1;
            break;
        }
        else
        {
            wins[a[x] % 2]++;
        }
    }

    if (s == -1 || wins[last] <= wins[!last])
        s = -1;
    else
        s = wins[last];

    return s;
}

int main()
{ _
    int n; cin >> n;
    vi a(n); READ(a);

    vvi sum(2, vi(n, 0));
    for (int i = 0; i < n; ++i)
    {
        sum[a[i] % 2][i] = 1;

        if (i)
        {
            sum[0][i] += sum[0][i - 1];
            sum[1][i] += sum[1][i - 1];
        }
    }

    vii ans;

    for (int t = 1; t <= n; ++t)
    {
        int s = sets(t, a, sum);

        if (s != -1)
            ans.pb(mp(s, t));
    }

    sort(ALL(ans));

    cout << SZ(ans) << endl;
    for (auto [s, t] : ans)
        cout << s << " " << t << endl;

    exit(0);
}

/*
 * INT_MAX      ~  2 * 1e9  ~ 2^31 - 1
 * LLONG_MAX    ~  9 * 1e18 ~ 2^63 - 1
 * ULLONG_MAX   ~ 18 * 1e18 ~ 2^64 - 1
 *
 * INF  ~ 1.0 * 1e9
 * LINF ~ 4.5 * 1e18
 *
 * CHECK:
 *      OVERFLOW
 *      IF/LOOP CONDITIONS
 *      CREATION OF STL CONTAINERS
*/