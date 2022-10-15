#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

class BIT
{
private:
    vi ft;
    int LSOne(int i) { return i & (-i); };
    int RSQ(int b)
    {
        int sum = 0;
        for (int i = b; i; i -= LSOne(i))
            sum ^= ft[i];
        return sum;
    }
public:
    BIT(int n)
    {
        ft.assign(n + 1, 0);
    }
    int RSQ(int a, int b)
    {
        ++a, ++b;
        return RSQ(b) ^ (a == 1 ? 0 : RSQ(a - 1));
    }
    void adjust(int k, int v)
    {
        ++k;
        for (int i = k; i < (int)ft.size(); i += LSOne(i))
            ft[i] ^= v;
    }
};

int main()
{ _
    int n; cin >> n;
    vi a(n); READ(a);

    int m; cin >> m;

    vi l(m), r(m);
    for (int j = 0; j < m; ++j)
        cin >> l[j] >> r[j], --l[j], --r[j];

    vi I(m, 0); iota(ALL(I), 0);
    sort(ALL(I), [&l, &r](int i, int j){ return mp(r[i], l[i]) < mp(r[j], l[j]); });

    vi ans(m);

    int R = -1;
    map<int, int> H;

    BIT bit(n);

    for (auto j : I)
    {
        for (int i = R + 1; i <= r[j]; ++i)
        {
            if (H.count(a[i]))
                bit.adjust(H[a[i]], a[i]);
            H[a[i]] = i;
            bit.adjust(i, a[i]);
        }
        ans[j] = bit.RSQ(l[j], r[j]);
        R = r[j];
    }

    vi XOR(n, 0); XOR[0] = a[0];
    for (int i = 1; i < n; ++i)
        XOR[i] = XOR[i - 1] ^ a[i];

    auto RQX = [&XOR](int l, int r)
    {
        return XOR[r] ^ (l > 0 ? XOR[l - 1] : 0);
    };

    for (int j = 0; j < m; ++j)
        ans[j] ^= RQX(l[j], r[j]);

    for (auto z : ans)
        cout << z << endl;

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
 *
 * CHECK:
 *      OVERFLOW
 *      IF/LOOP CONDITIONS
 *      CREATION OF STL CONTAINERS
*/