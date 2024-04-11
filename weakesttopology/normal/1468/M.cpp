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

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> a(n);
    vector<int> values;

    for (auto& v : a)
    {
        int k;
        cin >> k;
        v.resize(k);
        for (auto& x : v) cin >> x;
        values.insert(end(values), all(v));
    }

    sort(all(values)), values.erase(unique(all(values)), end(values));

    for (auto& v : a)
    {
        for (auto& x : v)
        {
            auto iter = lower_bound(all(values), x);
            x = (int)distance(begin(values), iter);
        }
    }

    const int K = 500, Z = size(values);

    vector<vector<int>> occ(Z);

    for (int i = 0; i < n; ++i)
    {
        for (auto x : a[i]) occ[x].push_back(i);
    }

    bool found = false;
    int p = -1, q = -1;

    // solve large
    {
        for (int i = 0; i < n && not found; ++i) if (size(a[i]) >= K)
        {
            vector<int> vis(n, 0);
            for (auto x : a[i])
            {
                for (auto j : occ[x]) if (j != i)
                {
                    if (not vis[j]) vis[j] = 1;
                    else
                    {
                        p = i, q = j, found = true;
                        break;
                    }
                }
                if (found) break;
            }
        }
    }
    // solve small
    {
        auto pred = [&](int i){ return size(a[i]) >= K; };
        for (int x = 0; x < Z; ++x)
        {
            occ[x].erase(remove_if(all(occ[x]), pred), end(occ[x]));
        }

        vector<int> vis(Z, -1);
        for (int x = 0; x < Z && not found; ++x)
        {
            for (auto i : occ[x])
            {
                for (auto y : a[i]) if (y != x)
                {
                    if (vis[y] == -1) vis[y] = i;
                    else
                    {
                        p = i, q = vis[y], found = true;
                        break;
                    }
                }
                if (found) break;
            }
            for (auto i : occ[x]) for (auto y : a[i]) vis[y] = -1;
        }
    }

    if (found) cout << p + 1 << " " << q + 1 << endl;
    else cout << -1 << endl;
}

int main()
{ _
    int t;
    cin >> t;
    while (t--) solve();
    exit(0);
}