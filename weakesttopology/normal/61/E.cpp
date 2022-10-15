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

const int N = 1e6;

struct Segtree
{
    int n;
    vll st;

    const ll default_value = 0;
    ll op(ll l, ll r)
    {
        return l + r;
    }

    void build()
    {
        for (int i = n - 1; i > 0; --i)
            st[i] = op(st[i << 1], st[i << 1 | 1]);
    }

    void modify(int p, ll value)
    {
        for (st[p += n] = value; p > 1; p >>= 1)
            st[p >> 1] = op(st[p], st[p ^ 1]);
    }

    // inclusive
    ll query(int l, int r)
    {
        ll res = default_value;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = op(st[l++], res);
            if (r & 1)
                res = op(res, st[--r]);
        }
        return res;
    }
};

int main()
{ _
    int n; cin >> n;
    vi a(n, 0); READ(a);

    Segtree T[2];
    T[0].n = n, T[1].n = n;
    T[0].st.assign(2 * N, 0);
    T[1].st.assign(2 * N, 0);

    vi I(n);
    for (int i = 0; i < n; ++i)
    {
        I[i] = i;
        T[0].st[n + i] = 0;
        T[1].st[n + i] = 0;
    }
    T[0].build(), T[1].build();

    sort(ALL(I), [&a](int i, int j){ return a[i] > a[j]; });

    ll ans = 0;

    for (auto i : I)
    {
        ans += T[1].query(0, i);

        ll q = T[0].query(0, i);
        T[0].modify(i, 1);
        T[1].modify(i, q);
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