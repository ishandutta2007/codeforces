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
        int n; cin >> n;
        vi p(n); READ(p);

        vi L(n), R(n);
        L[0] = 0, R[n - 1] = n - 1;

        for (int i = 1; i < n; ++i)
            L[i] = p[i] < p[L[i - 1]] ? i : L[i - 1];
        for (int i = n - 2; i >= 0; --i)
            R[i] = p[i] < p[R[i + 1]] ? i : R[i + 1];

        int ans = -1;

        for (int i = 1; i < n - 1; ++i)
            if (p[i] > max(p[L[i - 1]], p[R[i + 1]]))
                ans = i;

        if (ans == -1)
            cout << "NO\n";
        else
            cout << "YES\n" << L[ans] + 1 << " " << ans + 1 << " " << R[ans] + 1 << endl;
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