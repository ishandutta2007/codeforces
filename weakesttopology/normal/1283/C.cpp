#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define mp(x, y) make_pair(x, y)
#define ALL(X) X.begin(), X.end()
#define READ(X) for (int i = 0; i < (int)X.size(); ++i) cin >> X[i];

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
    int n; cin >> n;
    vi f(n), g(n, 0); READ(f);

    for (int i = 0; i < n; ++i)
        g[f[i] - 1] = i + 1;

    vii C;

    vi vis(n, 0);
    for (int i = 0; i < n; ++i)
    {
        if (vis[i])
            continue;

        vis[i] = 1;

        int j = i, k = i;

        bool b = false, e = false;
        while (g[j] && (i != j || not b))
        {
            b = true;
            j = g[j] - 1;
            vis[j] = 1;
        }
        while (f[k] && (i != k || not e))
        {
            e = true;
            k = f[k] - 1;
            vis[k] = 1;
        }

        if ((j != i || i != k) || not (b || e))
            C.pb(mp(j, k));
    }

    for (int z = 1; z < (int)C.size(); ++z)
        f[C[z - 1].s] = C[z].f + 1;

    f[C.back().s] = C[0].f + 1;

    for (auto x : f)
        cout << x << " ";
    cout << endl;

    exit(0);
}