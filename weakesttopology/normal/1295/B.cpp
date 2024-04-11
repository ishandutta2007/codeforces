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
    int T; cin >> T;
    while (T--)
    {
        int n, x; cin >> n >> x;
        string s; cin >> s;

        vi b(n, 0); b[0] = (s[0] == '0' ? 1 : -1);

        bool found = false;

        for (int i = 1; i < n; ++i)
        {
            b[i] += b[i - 1] + (s[i] == '0' ? 1 : -1);
            found = found || (b[i] == x);
        }

        found = found || (x == 0) || (b[0] == x);

        int var = b[n - 1], ans = 0;

        if (found && var == 0)
            ans = -1;
        else if (not found && var == 0)
            ans = 0;
        else
        {
            if (x == 0)
                ans += 1;

            for (int i = 0; i < n; ++i)
                ans += (b[i] == x) + (((b[i] - x) % var == 0) && (b[i] -x) / var <= -1);
        }

        cout << ans << endl;
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