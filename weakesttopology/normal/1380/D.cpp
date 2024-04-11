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
    int n, m, k; cin >> n >> m;
    ll x, y; cin >> x >> k >> y;

    vi a(n); READ(a);
    vi b(m); READ(b);

    for (int i = 0; i < n; ++i)
        ++a[i];
    for (int j = 0; j < m; ++j)
        ++b[j];

    a.insert(a.begin(), 0); a.pb(1);
    b.insert(b.begin(), 0); b.pb(1);

    n += 2, m += 2;

    vi pos(n);
    for (int i = 0; i < n; ++i)
        pos[a[i]] = i;

    for (int j = 1; j < m; ++j)
        if (pos[b[j]] < pos[b[j - 1]])
        {
            cout << -1 << endl;
            exit(0);
        }

    ll ans = 0;
    for (int j = 0; j + 1 < m; ++j)
    {
        int s = pos[b[j]], e = pos[b[j + 1]];

        if (s + 1 == e)
            continue;

        bool found = false;
        for (int i = s + 1; i < e; ++i)
            if (a[i] > max(a[s], a[e]))
                found = true;

        int L = e - s - 1, MAX = L / k;

        if (not found)
            ans += MAX * min(x, y * k) + (L % k) * y;
        else if (L < k)
        {
            cout << -1 << endl;
            exit(0);
        }
        else
        {
            ll c1 = MAX * x + (L % k) * y;
            ll c2 = x + (L - k) * y;
            ans += min(c1, c2);
        }
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