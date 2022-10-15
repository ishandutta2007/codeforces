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

struct SegmentTreePair
{
    int n;
    ii st[2 * N];

    const ii default_value = mp(-INF, INF);
    ii op(ii l, ii r)
    {
        return mp(max(l.f, r.f), min(l.s, r.s));
    }

    void build()
    {
        for (int i = n - 1; i > 0; --i)
            st[i] = op(st[i << 1], st[i << 1 | 1]);
    }

    ii query(int l, int r)
    {
        ii res = default_value;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = op(st[l++], res);
            if (r & 1)
                res = op(res, st[--r]);
        }
        return res;
    }

    int diff(ii x)
    {
        return abs(x.f - x.s);
    }
};

struct SegmentTreeDP
{
    int n;
    int st[2 * N];

    const int default_value = INF;
    int op(int l, int r)
    {
        return min(l, r);
    }

    void build()
    {
        for (int i = n - 1; i > 0; --i)
            st[i] = op(st[i << 1], st[i << 1 | 1]);
    }

    void modify(int p, int value)
    {
        for (st[p += n] = value; p > 1; p >>= 1)
            st[p >> 1] = op(st[p], st[p ^ 1]);
    }

    int query(int l, int r)
    {
        int res = default_value;
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

int diff(ii P)
{
    return abs(P.f - P.s);
}

int main()
{ _
    int n, s, l; cin >> n >> s >> l;
    vi a(n); READ(a);

    if (l > n)
    {
        cout << -1 << endl;
        exit(0);
    }

    SegmentTreePair TREE;
    SegmentTreeDP DP;

    TREE.n = n;
    DP.n = n;
    for (int i = 0; i < n; ++i)
    {
        TREE.st[n + i] = mp(a[i], a[i]);
        DP.st[n + i] = INF;
    }
    DP.st[2 * n - l] = 1;

    TREE.build();
    DP.build();

    if (diff(TREE.query(n - l, n - 1)) > s)
    {
        cout << -1 << endl;
        exit(0);
    }

    for (int x = n - l - 1; x >= 0; --x)
    {
        if (diff(TREE.query(x, x + l - 1)) > s)
            continue;

        int y = x + l - 1;
        for (int z = n - 1 - y; z; z >>= 1)
            while (y + z < n && diff(TREE.query(x, y + z)) <= s)
                y += z;

        if (y == n - 1)
            DP.modify(x, 1);
        else
        {
            int v = DP.query(x + l, y + 1);
            DP.modify(x, min(1 + v, INF));
        }
    }

    int ans = DP.query(0, 0);

    if (ans == INF)
        ans = -1;

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