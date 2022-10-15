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
    int n, m; cin >> n >> m;
    vi a(n); READ(a);

    map<int, ii> H;
    for (int j = 0; j < m; ++j)
    {
        int t, b; cin >> t >> b; --b;
        H[b] = mp(j, t);
    }

    queue<ii> q; int l = -1;
    for (auto iter = H.rbegin(); iter != H.rend(); ++iter)
    {
        int b = iter->f, j = iter->s.f, t = iter->s.s;
        if (j > l)
        {
            q.push(mp(b, t));
            l = j;
        }
    }

    vi I(n, -1);
    int s = 0, e = q.front().f;

    vi X = a; sort(X.begin(), X.begin() + e + 1);

    while (not q.empty())
    {
        int b, t; tie(b, t) = q.front(); q.pop();

        int nb = q.empty() ? -1 : q.front().f;

        if (t == 1)
            for (int i = b; i > nb; --i, --e)
                I[i] = e;
        else
            for (int i = b; i > nb; --i, ++s)
                I[i] = s;
    }

    vi ans = a;

    for (int i = 0; i < n && I[i] != -1; ++i)
        ans[i] = X[I[i]];

    for (auto z : ans)
        cout << z << " ";
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