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

const int N = 2 * 1e5;

void dfs(const vvi& E, vi& vis, int u)
{
    vis[u] = 1;

    for (auto v : E[u])
        if(not vis[v])
            dfs(E, vis, v);
}

int main()
{ _
    int n; cin >> n;

    vii I(n);
    for (int i = 0; i < n; ++i)
        cin >> I[i].f >> I[i].s;

    sort(ALL(I));

    vii Q;
    for (int i = 0; i < n; ++i)
    {
        Q.push_back({I[i].f, i});
        Q.push_back({I[i].s, - i - 1});
    }

    sort(ALL(Q));

    int m = 0;
    vvi E(n);

    set<ii> A;

    for (auto [x, i] : Q)
    {
        if (m >= n)
            break;

        if (i < 0)
        {
            i = - (i + 1);

            auto curr = A.find(mp(I[i].f, i));

            for (auto iter = next(curr); iter != A.end(); ++iter, ++m)
            {
                E[iter->s].pb(i);
                E[i].pb(iter->s);
            }

            A.erase(mp(I[i].f, i));
        }
        else
            A.insert(mp(I[i].f, i));
    }

    vi vis(n, 0); dfs(E, vis, 0);

    int c = accumulate(ALL(vis), 0);

    if (c == n && m == n - 1)
        cout << "YES\n";
    else
        cout << "NO\n";

    exit(0);
}