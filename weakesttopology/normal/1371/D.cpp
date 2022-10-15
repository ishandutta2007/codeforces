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
    int t; cin >> t;
    while (t--)
    {
        int n, k; cin >> n >> k;

        vvi A(n, vi(n, 0));

        for (int i = 0; i < k; ++i)
            A[i % n][(i / n + i % n) % n] = 1;

        int R_max = 0, R_min = INF, C_max = 0, C_min = INF;

        for (int i = 0; i < n; ++i)
        {
            int row = 0, col = 0;
            for (int j = 0; j < n; ++j)
            {
                row += A[i][j];
                col += A[j][i];
            }

            R_max = max(R_max, row);
            R_min = min(R_min, row);
            C_max = max(C_max, col);
            C_min = min(C_min, col);
        }

        ll ans = (R_max - R_min) * (R_max - R_min) + (C_max - C_min) * (C_max - C_min);

        cout << ans << endl;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                cout << A[i][j];
            cout << endl;
        }
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