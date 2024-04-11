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

struct SegmentTree
{
    int n;
    int st[2 * N];

    int op(int l, int r)
    {
        return max(l, r);
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

    // inclusive
    int query(int l, int r)
    {
        int res = st[n + l];
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

    vector<pair<ii, int>> D(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> D[i].f.f >> D[i].f.s;
        D[i].s = i;
    }
    auto COPY = D;
    sort(ALL(D));

    vi x(n), h(n);
    for (int i = 0; i < n; ++i)
        tie(x[i], h[i]) = D[i].f;

    vi L(n, n - 1);
    for (int i = 0; i < n; ++i)
    {
        int b = i;
        for (int z = n - 1 - b; z; z >>= 1)
            while (b + z < n && x[b + z] < x[i] + h[i])
                b += z;
        L[i] = b;
    }

    SegmentTree TREE; TREE.n = n;
    for (int i = 0; i < n; ++i)
        TREE.st[n + i] = 0;
    TREE.build();

    vi ans(n, 1);
    TREE.modify(n - 1, n);
    for (int i = n - 1; i >= 0; --i)
    {
        ans[i] = max(1, TREE.query(i, L[i]) - i);
        TREE.modify(i, ans[i] + i);
    }

    vi ANS(n);
    for (int i = 0; i < n; ++i)
        ANS[D[i].s] = ans[i];

    for (auto w : ANS)
        cout << w << " ";
    cout << endl;

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