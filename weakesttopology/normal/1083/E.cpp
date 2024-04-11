
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

std::ostream&
operator<<( std::ostream& dest, __int128 value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}

typedef __int128 ftype;
typedef complex<ftype> point;

vll Y;

struct Hull
{
    const int h = 20;
    const int N = 1 << h; // needs to be power of 2
    vector<point> line; // initialize to point(0, INF)

    Hull(int h = 20) : h(h), N(1 << h)
    {
        line.assign(2 * N, point(0, __int128(LINF) * __int128(LINF)));
    }

    ftype dot(point a, point b)
    {
        return (conj(a) * b).real();
    }

    ftype f(point a, ftype x)
    {
        if (x >= SZ(Y))
            return __int128(LINF) * __int128(LINF);
        return dot(a, {Y[x], 1});
    }

    void update(point nw)
    {
        for (int p = 1, d = h; p < 2 * N; --d)
        {
            int l = (p << d) - N, m = p < N ? ((p << d) | ((1 << (d - 1)) - 1)) - N : p - N;
            bool left = f(nw, l) < f(line[p], l);
            bool mid = f(nw, m) < f(line[p], m);

            if (mid)
                swap(line[p], nw);

            if (left != mid)
                p = p << 1;
            else
                p = p << 1 | 1;
        }
    }

    ftype get(ftype x)
    {
        int p = N + x;
        ftype res = f(line[p], x);
        while (p)
            res = min(res, f(line[p >>= 1], x));
        return res;
    }
};

int main()
{ _
    int n; cin >> n;

    vll x(n), y(n), a(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i] >> a[i];

    Y = y; sort(ALL(Y));
    map<ll, int> pos;
    for (int i = 0; i < n; ++i)
        pos[Y[i]] = i;

    vi I(n, 0); iota(ALL(I), 0); sort(ALL(I), [&x](int i, int j){ return x[i] < x[j]; });

    int s = I[0];
    vector<__int128> dp(n, 0); dp[s] = x[s] * y[s] - a[s];

    if (n == 1)
    {
        cout << dp[s] << endl;
        exit(0);
    }

    __int128 ans = dp[s];
    Hull hull; hull.update(point(x[s], -dp[s]));

    I.erase(I.begin());
    for (auto i : I)
    {
        dp[i] = -hull.get(pos[y[i]]) + (x[i] * y[i] - a[i]);
        dp[i] = max(dp[i], ftype(x[i] * y[i] - a[i]));
        ans = max(ans, dp[i]);
        hull.update(point(x[i], -dp[i]));
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