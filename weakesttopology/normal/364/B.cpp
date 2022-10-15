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

const int N = 2 * 1e6;
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
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = op(st[l++], res);
        if (r & 1)
            res = op(res, st[--r]);
    }
    return res;
}

int main()
{ _
    int n0, d; cin >> n0 >> d;

    vi c(n0); READ(c);

    int M = 0;
    for (int i = 0; i < n0; ++i)
        M += c[i];

    vi sum(M + 1, 0); sum[0] = 1;
    for (int i = 0; i < n0; ++i)
    {
        vi sumt(M + 1, 0);
        for (int j = 0; j < M + 1; ++j)
            if (sum[j])
                sumt[j + c[i]] = 1;
        for (int j = 0; j < M + 1; ++j)
            sum[j] = sum[j] || sumt[j];
    }

    n = M + 1;
    for (int i = 0; i < n; ++i)
        st[n + i] = INF;
    st[n] = 0;
    build();

    for (int j = 1; j < M + 1; ++j)
        if (sum[j])
            modify(j, query(max(0, j - d), j) + 1);

    int i = M;
    while (query(i, i + 1) >= INF)
        --i;

    cout << i << " " << query(i, i + 1) << endl;

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