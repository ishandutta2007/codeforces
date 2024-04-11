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
#define READ(X) for (int i0 = 0; i0 < (int)X.size(); ++i0) cin >> X[i0]
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

int min(const vi& b, int mask)
{
    int r = INF;
    for (int i = 0; i < SZ(b); ++i)
        if ((1 << i) & mask)
            r = min(r, b[i]);

    return r;
}

int main()
{ _
    int n, m; cin >> n >> m;

    vvi a(n, vi(m));
    for (int i = 0; i < n; ++i)
        READ(a[i]);

    int T = 1 << m;
    vi S(T, 0);

    for (int i = 0; i < n; ++i)
        for (int mask = 0; mask < T; ++mask)
            if (min(a[i], mask) > min(a[S[mask]], mask))
                S[mask] = i;

    int opt = min(a[0], T - 1);
    ii ans = mp(0, 0);

    for (int mask = 0; mask < T; ++mask)
    {
        int v = min(min(a[S[mask]], mask), min(a[S[~mask & (T - 1)]], ~mask));
        if (v > opt)
        {
            opt = v;
            ans = mp(S[mask], S[~mask & (T - 1)]);
        }
    }

    cout << ans.f + 1 << " " << ans.s + 1 << endl;

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