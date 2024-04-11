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

vvi E;
vi init, goal, visited;

vi output;

void dfs_flip(int u, vi flip, int h = 0)
{
    visited[u] = true;

    bool f = (flip[h % 2] != init[u]) != goal[u];
    if (f)
    {
        output.pb(u + 1);
        flip[h % 2] = flip[h % 2] != 1;
    }

    for (auto v : E[u])
    {
        if (visited[v]) continue;

        dfs_flip(v, flip, h + 1);
    }
}

int main()
{ _
    int n; cin >> n;
    E = vvi(n);
    visited = init = goal = vi(n, 0);
    for (int i = 1; i < n; ++i)
    {
        int u, v; cin >> u >> v;
        u--; v--;
        E[u].pb(v); E[v].pb(u);
    }
    for (int i = 0; i < n; ++i)
        cin >> init[i];
    for (int i = 0; i < n; ++i)
        cin >> goal[i];

    vi flip(2, 0);
    dfs_flip(0, flip);

    cout << output.size() << endl;
    for (auto x : output)
        cout << x << endl;

    exit(0);
}