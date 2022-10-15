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
    int n, q; cin >> n >> q;
    vi a(n); READ(a);

    const int N = 5 * 1e5;
    int lp[N + 1] = { 0 };
    vi pr;

    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.pb(i);
        }
        for (auto p : pr)
        {
            if (p > lp[i] || i * p > N)
                break;
            lp[i * p] = p;
        }
    }

    int div[N + 1] = { 0 };

    auto bad = [&div, &lp](int w, int sw = 0)
    {
        vi f;
        while (lp[w])
        {
            f.pb(lp[w]);
            int t = w;
            while (t % lp[w] == 0)
                t /= lp[w];
            w = t;
        }

        int m = 0;
        for (int mask = 1; mask < (1 << SZ(f)); ++mask)
        {
            int y = 1;
            for (int i = 0; (1 << i) <= mask; ++i)
                if ((1 << i) & mask)
                    y *= f[i];
            m += div[y] * (__builtin_popcount(mask) % 2 ? 1 : -1);
            div[y] += sw;
        }
        return m;
    };

    ll c = 0, bad_pairs = 0;

    vi shelf(n, 0);
    for (int z = 0; z < q; ++z)
    {
        int x; cin >> x; --x;

        if (not shelf[x])
        {
            if (a[x] != 1)
                bad_pairs += bad(a[x], 1);
            ++c;
        }
        else
        {
            if (a[x] != 1)
            {
                bad(a[x], -1);
                bad_pairs -= bad(a[x], 0);
            }
            --c;
        }

        shelf[x] = !shelf[x];

        ll ans = c * (c - 1) / 2 - bad_pairs;
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