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
    int n, m; cin >> n >> m;
    set<pair<int,ii>> S;

    for (int i = 0; i < m; ++i)
    {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        S.insert(mp(w, mp(u, v)));
    }

    int M = 1;

    vvi SZ(n), W(n);

    for (auto [w, e] : S)
    {
        int u = e.f, v = e.s;

        auto iter = lower_bound(W[u].begin(), W[u].end(), w);

        W[v].pb(w);

        if (iter != W[u].begin())
        {
            iter = prev(iter);

            int sz = SZ[u][distance(W[u].begin(), iter)] + 1;

            if (not SZ[v].empty())
                SZ[v].pb(max(*SZ[v].rbegin(), sz));
            else
                SZ[v].pb(sz);
        }
        else
        {
            if (not SZ[v].empty())
                SZ[v].pb(*SZ[v].rbegin());
            else
                SZ[v].pb(1);
        }


        M = max(M, *SZ[v].rbegin());
    }

    cout << M << endl;

    exit(0);
}