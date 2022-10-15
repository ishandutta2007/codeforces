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

int main()
{ _
    int n, m; cin >> n >> m;

    vi x(m), y(m);
    vvi B(2, vi(n, 0));
    for (int j = 0; j < m; ++j)
    {
        cin >> x[j] >> y[j];
        --x[j], --y[j];
        B[0][x[j]] = 1;
        B[1][y[j]] = 1;
    }

    int ans = 0;

    for (int i = 1; i < n / 2; ++i)
    {
        int b = B[0][i] + B[0][n - 1 - i] + B[1][i] + B[1][n - i - 1];
        ans += 4 - b;
    }

    if (n % 2)
    {
        int b = min(B[0][n / 2], B[1][n / 2]);
        ans += 1 - b;
    }

    cout << ans << endl;

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