#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds; // policy-based

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int b(int p) { return p & (-p); }

int main()
{ _
    int n, m; cin >> n >> m;

    vector<int> invp(n), q(n);

    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x; --x;
        invp[x] = i;
    }

    vector<ordered_set<int>> bit(n + 1);

    auto update = [&](int p, int x)
    {
        for (int i = p + 1; i <= n; i += b(i))
        {
            auto [iter, good] = bit[i].insert(x);
            if (not good) bit[i].erase(iter);
        }
    };
    auto query_prefix = [&](int la, int ra, int p)
    {
        int res = 0;
        for (int i = p; i >= 1; i -= b(i))
        {
            res += (int)bit[i].order_of_key(ra + 1);
            res -= (int)bit[i].order_of_key(la);
        }
        return res;
    };
    auto query = [&](int la, int ra, int lb, int rb)
    {
        return query_prefix(la, ra, rb + 1) - query_prefix(la, ra, lb);
    };

    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x; --x;
        q[i] = x = invp[x];
        update(i, x);
    }

    for (int j = 0; j < m; ++j)
    {
        int type; cin >> type;

        if (type == 1)
        {
            int la, ra, lb, rb;
            cin >> la >> ra >> lb >> rb;
            --la, --ra, --lb, --rb;

            int ans = query(la, ra, lb, rb);
            cout << ans << endl;
        }
        else
        {
            int x, y; cin >> x >> y; --x, --y;

            for (auto z : { x, y }) update(z, q[z]);

            swap(q[x], q[y]);

            for (auto z : { x, y }) update(z, q[z]);
        }
    }

    exit(0);
}