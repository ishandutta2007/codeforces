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

int tri(int x)
{
    return (x * (x - 1) * (x - 2)) / 6;
}

int main()
{ _
    int n = 100, k; cin >> k;

    string e;
    for (int i = 0; i < n; ++i)
        e.pb('0');

    vector<string> E(n, e);

    vii blocks;

    for (int m = 0; k && m < n && blocks.empty();)
    {
        int sz = 0;
        for (int b = n - m; b; b /= 2)
            while (sz + b <= n - m && tri(sz + b) <= k)
                sz += b;
        k -= tri(sz);

        if (sz < 3)
            break;

        blocks.pb(mp(m, m + sz));
        m += sz;
    }

    for (auto B : blocks)
        for (int i = B.f; i < B.s; ++i)
            for (int j = i + 1; j < B.s; ++j)
                for (int l = j + 1; l < B.s; ++l)
                    E[i][j] = E[j][i] = E[j][l] = E[l][j] = E[i][l] = E[l][i] = '1';

    for (int i = blocks.rbegin()->s; i < n; ++i)
        blocks.pb(mp(i, i + 1));

    for (int x = 0; x < SZ(blocks) && k; ++x)
        for (int y = x + 1; y < SZ(blocks) && k; ++y)
        {
            ii B = blocks[x], C = blocks[y];

            int m = 0;

            for (int i = B.f; i < B.s && k; ++i)
                for (int j = C.f; j < C.s && k; ++j)
                    if (m <= k)
                    {
                        E[i][j] = E[j][i] = '1';
                        k -= m;
                        m++;
                    }
        }

    cout << n << endl;

    for (auto s : E)
        cout << s << endl;

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