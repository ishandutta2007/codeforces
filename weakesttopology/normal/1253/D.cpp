#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n';

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n;
vvi E;
vi C;

void dfs(int u)
{
    for (auto v : E[u])
    {
        if (C[v] == -1)
        {
            C[v] = C[u];
            dfs(v);
        }
    }
}


int main()
{
    cin >> n;
    E.assign(n, vi());
    C.assign(n, -1);
    int m; cin >> m;
    for (int j = 0; j < m; ++j)
    {
        int u, v; cin >> u >> v;
        u--; v--;
        E[u].pb(v);
        E[v].pb(u);
    }

    int c = 0;
    for (int i = 0; i < n; ++i)
        if (C[i] == -1)
        {
            C[i] = ++c;
            dfs(i);
        }

    int ans = 0;
    map<int, int> H, G, F;

    for (int i = 0; i < n; ++i)
        G[C[i]]++;

    for (int i = 0; i < n; ++i)
    {
        int x = C[i];
        H[x]++;
        G[x]--;
        F[x]++;

        if (G[x] == 0)
            G.erase(x);

        if ((int)F.size() + (int)G.size() == c)
        {
            ans += H.size() - 1;
            H.clear();
        }
    }

    cout << ans << endl;

    exit(0);
}