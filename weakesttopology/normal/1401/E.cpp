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
    int n, m; cin >> n >> m;

    const int N = 1e6;

    ll ans = 1;

    vector E(0, tuple(0, 0, 0));
    for (int i = 0; i < n; ++i)
    {
        int y, lx, rx; cin >> y >> lx >> rx;
        E.push_back({lx, 0, y}), E.push_back({rx, 2, y});
        if (lx <= 0 && N <= rx) ++ans;
    }

    vector ly(m, 0), ry(m, 0);
    for (int j = 0; j < m; ++j)
    {
        int x; cin >> x >> ly[j] >> ry[j];
        E.push_back({x, 1, j});
    }

    sort(all(E));

    ordered_set<int> S; S.insert(0), S.insert(N);

    auto update = [&](int x)
    {
        if (S.find(x) != S.end()) S.erase(x);
        else S.insert(x);
    };

    for (auto [x, t, y] : E)
    {
        if (t != 1) update(y);
        else
            ans += S.order_of_key(ry[y] + 1) - S.order_of_key(ly[y]) - 1;
    }

    cout << ans << endl;

    exit(0);
}