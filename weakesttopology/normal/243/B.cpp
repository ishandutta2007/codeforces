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

int intersection(const set<int>& S, const set<int>& T)
{
    int c = 0;
    for (auto x : S)
        c += !!T.count(x);
    return c;
}

int main()
{ _
    int n, m, h, t; cin >> n >> m >> h >> t;

    vector<set<int>> E(n); vi d(n, 0);
    vvi F(n);
    for (int j = 0; j < m; ++j)
    {
        int a, b; cin >> a >> b; --a, --b;
        E[a].insert(b), E[b].insert(a);
        F[a].pb(b), F[b].pb(a);
        ++d[a], ++d[b];
    }

    int u = -1, v = -1;

    vi temp(n, 0);

    for (int x = 0; x < n; ++x)
    {
        for (auto y : F[x])
        {
            if (d[x] < h + 1 || d[y] < t + 1)
                continue;

            if (max(d[x], d[y]) >= h + t + 1)
            {
                u = x, v = y;
                x = n; break;
            }

            int I = 0;
            for (auto w : F[x])
                temp[w] = 1;
            for (auto w : F[y])
                I += temp[w];
            for (auto w : F[x])
                temp[w] = 0;

            if (d[x] >= h + 1 && max(0, h - (d[x] - 1 - I)) + max(0, t - (d[y] - 1 - I)) <= I)
            {
                u = x, v = y;
                x = n; break;
            }
        }
    }

    if (u == -1)
        cout << "NO\n";
    else
    {
        cout << "YES\n";

        set<int> H, T;
        int x = u, y = v;

        if (d[y] >= h + t + 1)
        {
            for (auto w : E[x])
            {
                if (SZ(H) == h)
                    break;
                if (w == y)
                    continue;
                H.insert(w);
            }
            for (auto w : E[y])
            {
                if (SZ(T) == t)
                    break;
                if (w == x || H.count(w))
                    continue;
                T.insert(w);
            }
        }
        else
        {
            int z = max(0, h - (d[x] - 1 - intersection(E[y], E[x])));
            for (auto w : E[x])
            {
                if (SZ(H) == h)
                    break;
                if (w == y || (not z && E[y].count(w)))
                    continue;
                z -= E[y].count(w);
                H.insert(w);
            }
            for (auto w : E[y])
            {
                if (SZ(T) == t)
                    break;
                if (w == x || H.count(w))
                    continue;
                T.insert(w);
            }
        }

        cout << u + 1 << " " << v + 1 << endl;
        for (auto w : H)
            cout << w + 1 << " ";
        cout << endl;
        for (auto w : T)
            cout << w + 1 << " ";
        cout << endl;
    }

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