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

bool spaced(vi I, int l, int e)
{
    if (e < l)
        return false;

    sort(I.begin(), I.begin() + e);

    int c = 1;
    for (int i = 1, last = I[0]; c < l && i < e; ++i)
        if (I[i] > last + 1)
        {
            ++c;
            last = I[i];
        }

    return c == l;
}

int main()
{ _
    int n, k; cin >> n >> k;

    vi a(n); READ(a);

    vi I(n);
    for (int i = 0; i < n; I[i] = i, ++i);
    auto comp = [&a](int i, int j){ return a[i] < a[j]; };
    sort(ALL(I), comp);

    int ans = INF;

    // odds
    if (k % 2 == 0)
        I.erase(find(ALL(I), n - 1));

    int sz = (k + 1) / 2;
    int b = sz - 1;
    for (int z = SZ(I) - b; z; z /= 2)
        while (b + z <= SZ(I) && not spaced(I, sz, b + z))
            b += z;
    b += 1;

    ans = min(ans, a[I[b - 1]]);

    if (k % 2 == 0)
    {
        I.pb(n - 1);
        sort(ALL(I), comp);
    }

    // evens
    I.erase(find(ALL(I), 0));

    if (k % 2)
        I.erase(find(ALL(I), n - 1));

    sz = k / 2;
    b = sz - 1;
    for (int z = SZ(I) - b; z; z /= 2)
        while (b + z <= SZ(I) && not spaced(I, sz, b + z))
            b += z;
    b += 1;

    ans = min(ans, a[I[b - 1]]);

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