#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

int main()
{ _
    int n; cin >> n;
    vector a(n, 0);
    vector E(n, vector(0, 0));
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (0 <= i - a[i]) E[i - a[i]].push_back(i);
        if (i + a[i] < n) E[i + a[i]].push_back(i);
    }

    auto chmin = [](int& x, int y) { return y < x ? x = y, true : false; };

    auto bfs = [&](int b)
    {
        vector dist(n, INF);
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (a[i] % 2 == b)
            {
                dist[i] = 0; q.push(i);
            }

        while (not q.empty())
        {
            int u = q.front(); q.pop();

            for (auto v : E[u])
                if (chmin(dist[v], dist[u] + 1)) q.push(v);
        }

        return dist;
    };

    auto dist_even = bfs(0), dist_odd = bfs(1);

    vector d(n, 0);
    for (int i = 0; i < n; ++i)
    {
        d[i] = max(dist_even[i], dist_odd[i]);
        if (d[i] == INF) d[i] = -1;
    }

    for (auto x : d)
        cout << x << " ";
    cout << endl;

    exit(0);
}