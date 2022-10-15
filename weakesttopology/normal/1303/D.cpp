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

int solve()
{
    ll n; int m; cin >> n >> m;
    const int N = 100;
    vector ct(N + 1, 0);
    ll sum = 0;
    for (int j = 0; j < m; ++j)
    {
        int a; cin >> a;
        ct[31 - __builtin_clz(a)]++;
        sum += a;
    }
    if (sum < n) return -1;
    int ans = 0;
    for (int i = 0; i < N; ++i, n >>= 1)
    {
        if (n & 1)
        {
            if (ct[i]) --ct[i];
            else
            {
                int j = i;
                while (not ct[j]) ct[j++]++;
                --ct[j];
                ans += j - i;
            }
        }
        ct[i + 1] += ct[i] / 2;
    }
    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}