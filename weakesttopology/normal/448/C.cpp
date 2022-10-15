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

const int N = 2 * 1e5;
int n;
int st[N] = { 0 };

vi a;

int op(int l, int r)
{
    return a[l] <= a[r] ? l : r;
}

void build()
{
    for (int i = n - 1; i > 0; --i)
        st[i] = op(st[i << 1], st[i << 1 | 1]);
}

// inclusive
int query(int l, int r)
{
    int res = l;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = op(st[l++], res);
        if (r & 1)
            res = op(res, st[--r]);
    }
    return res;
}

int solve(int l, int r, int h)
{
    if (r < l)
        return 0;
    if (r == l)
        return !!(a[l] - h);

    int m = query(l, r);

    return min(r - l + 1, a[m] - h + solve(l, m - 1, a[m]) + solve(m + 1, r, a[m]));
}

int main()
{ _
    cin >> n;

    a.assign(n, 0); READ(a);
    iota(st + n, st + 2 * n, 0);
    build();

    int ans = solve(0, n - 1, 0);

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