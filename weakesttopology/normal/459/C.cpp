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

vi next(vi b, int k)
{
    b[0] += 1;
    for (int j = 0; j + 1 < SZ(b) && b[j] == k + 1; ++j)
    {
        b[j] = 1;
        b[j + 1] += 1;
    }
    return b;
}

int main()
{ _
    int n, k, d; cin >> n >> k >> d;

    vvi ans(n);

    if (k == 1 && n == 1)
        ans[0] = vi(d, 1);
    else if (k == 1 && n > 1)
    {
        cout << -1 << endl;
        exit(0);
    }
    else
    {
        ll p = 1;
        for (int z = 0; z < d && p < n; ++z, p *= k);

        if (p < n)
        {
            cout << -1 << endl;
            exit(0);
        }

        ans[0] = vi(d, 1);
        for (int i = 1; i < n; ++i)
            ans[i] = next(ans[i - 1], k);
    }

    for (int j = 0; j < d; ++j)
    {
        for (int i = 0; i < n; ++i)
            cout << ans[i][j] << " ";
        cout << endl;
    }

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