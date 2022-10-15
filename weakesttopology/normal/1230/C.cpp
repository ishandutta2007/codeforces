#include "bits/stdc++.h"

using namespace std;

int main(int argc, char *argv[])
{
    int n, m; cin >> n >> m;

    vector<vector<int>> E(n + 1);

    for (int j = 0; j < m; ++j)
    {
        int u, v; cin >> u >> v;

        E[u].push_back(v);
        E[v].push_back(u);
    }

    if (n < 7)
        cout << m << endl;

    else
    {
        int M = 0;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (i == j)
                    continue;

                set<int> N;
                for (auto v : E[i])
                    N.insert(v);
                for (auto v : E[j])
                    N.insert(v);

                int num_edges = m - E[i].size() - E[j].size() + N.size();

                M = max(M, num_edges);
            }
        }

        cout << min(M, 21) << endl;
    }

    return 0;
}