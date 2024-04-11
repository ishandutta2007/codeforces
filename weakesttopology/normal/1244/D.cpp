#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> I = { 0, 1, 2 };
vector<int> visited;
vector<int> color;
vector<vector<ll>> C;
vvi E;

ll cost(int u, int c)
{
    visited[u] = 1;

    ll sum = C[u][I[c]];
    color[u] = I[c];

    for (auto v : E[u])
        if (! visited[v])
            sum += cost(v, (c + 1) % 3);

    return sum;
}

int main()
{ _
    int n; cin >> n;
    C.assign(n, vector<ll>(3, 0));
    E.assign(n, vi());

    for (int c = 0; c < 3; ++c)
        for (int i = 0; i < n; ++i)
            cin >> C[i][c];

    for (int e = 0; e < n - 1; ++e)
    {
        int u, v; cin >> u >> v;
        u--; v--;
        E[u].pb(v);
        E[v].pb(u);
    }

    for (auto N : E)
        if (N.size() > 2)
        {
            cout << -1 << endl;
            exit(0);
        }

    int s = 0;
    for (int i = 0; i < n; ++i)
        if (E[i].size() == 1)
        {
            s = i; break;
        }

    ll m = LINF;
    vi opt;
    do
    {
        visited.assign(n, 0);
        color.assign(n, 0);
        ll x = cost(s, 0);
        if (x < m)
        {
            m = x;
            opt = color;
        }
    } while (next_permutation(I.begin(), I.end()));

    cout << m << endl;
    for (auto c : opt)
        cout << c + 1 << " ";
    cout << endl;

    exit(0);
}