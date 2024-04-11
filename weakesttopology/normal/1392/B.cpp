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

void solve()
{
    int n; cin >> n;
    ll k; cin >> k;
    vector a(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];

    {
        int d = *max_element(all(a));
        for (int i = 0; i < n; ++i)
            a[i] = d - a[i];
    }

    k = (k - 1) % 2;
    if (k)
    {
        int d = *max_element(all(a));
        for (int i = 0; i < n; ++i)
            a[i] = d - a[i];
    }
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{ _
    int t; cin >> t;
    while (t--) solve();
    exit(0);
}