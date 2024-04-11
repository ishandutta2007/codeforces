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

int ct = 0;
vi vis, L;

void dfs(const vvi& E, int u)
{
    vis[u] = 1;

    for (auto v : E[u])
        if (not vis[v])
            dfs(E, v);

    L[u] = ct++;
}

int main()
{ _
    int n, m; cin >> n >> m;
    vvi A(n, vi(m));
    for (int i = 0; i < n; ++i)
        READ(A[i]);

    int row;
    auto comp = [&A, &row](int i, int j) { return A[row][i] < A[row][j]; };

    vvi E(m + n * m); vi d(m + n * m);

    int dummy = m;

    for (int i = 0; i < n; ++i)
    {
        vi O;
        for (int j = 0; j < m; ++j)
            if (A[i][j] != -1)
                O.pb(j);

        row = i;
        sort(ALL(O), comp);

        for (int j = 0; j + 1 < SZ(O); ++j)
        {
            int k = j;
            while (k + 1 < SZ(O) && A[i][O[k + 1]] == A[i][O[j]])
                ++k;

            for (int z = j; z <= k; ++z)
                E[O[z]].pb(dummy), d[dummy]++;

            for (int w = k + 1; w < SZ(O) && A[i][O[w]] == A[i][O[k + 1]]; ++w)
                E[dummy].pb(O[w]), d[O[w]]++;

            ++dummy;

            j = k;
        }
    }

    vis.assign(m + n * m, 0), L.assign(m + n * m, 0);
    for (int j = 0; j < (n + 1) * m; ++j)
        if (not vis[j] && not d[j])
            dfs(E, j);

    if (accumulate(ALL(vis), 0) < m)
    {
        cout << -1 << endl;
        exit(0);
    }

    bool check = true;
    for (int j = 0; j < (n + 1) * m; ++j)
        for (auto k : E[j])
            if (L[k] >= L[j])
                check = false;

    if (not check)
        cout << -1 << endl;
    else
    {
        vi ans(m); iota(ALL(ans), 0);
        auto _L = L;
        sort(ALL(ans), [&_L](int j, int k) { return _L[j] > L[k]; });

        for (auto j : ans)
            cout << j + 1 << " ";
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