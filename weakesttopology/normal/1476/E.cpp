#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

void fail(string s = "")
{
    if (not empty(s)) debug(s);
    cout << "NO" << endl;
    exit(0);
}

int main()
{ _
    int n, m, k;
    cin >> n >> m >> k;

    map<string, int> mp;
    vector<string> p(n);

    for (int u = 0; u < n; ++u)
    {
        cin >> p[u];
        mp[p[u]] = u;
    }

    vector<vector<int>> E(n);
    vector<int> indeg(n, 0);

    for (int j = 0; j < m; ++j)
    {
        string s;
        int mt;
        cin >> s >> mt;
        --mt;

        for (int z = 0; z < k; ++z)
        {
            if (p[mt][z] != '_' && p[mt][z] != s[z]) fail("doesn't match");
        }

        string r(k, '*');
        for (int mask = 0; mask < (1 << k); ++mask)
        {
            for (int z = 0; z < k; ++z)
            {
                r[z] = (mask >> z & 1) ? s[z] : '_';
            }
            if (r != p[mt] && mp.count(r))
            {
                E[mt].push_back(mp[r]);
                indeg[mp[r]] += 1;
            }
        }
    }

    queue<int> q;
    for (int u = 0; u < n; ++u) if (indeg[u] == 0) q.push(u);

    vector<int> topo_sort;

    while (not empty(q))
    {
        int u = q.front();
        q.pop();
        topo_sort.push_back(u);
        for (auto v : E[u]) if (--indeg[v] == 0) q.push(v);
    }

    if (size(topo_sort) != n) fail("not a dag");

    cout << "YES" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << topo_sort[i] + 1 << "\n "[i + 1 < n];
    }

    exit(0);
}