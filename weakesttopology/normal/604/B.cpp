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
    int n, k; cin >> n >> k;
    vector s(n, 0);
    for (int i = 0; i < n; ++i) cin >> s[i];

    auto fit = [&](int x)
    {
        if (s.back() > x) return false;
        int m = 0;
        for (int i = 0, j = n - 1; i <= j; --j)
        {
            if (s[i] + s[j] <= x) ++i;
            ++m;
        }
        return m <= k;
    };

    int x = 0;
    for (int z = 2 * s.back(); z; z >>= 1)
        while (not fit(x + z)) x += z;

    cout << x + 1 << endl;

    exit(0);
}