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
#define read(x) for (int xx = 0; xx < sz(x); ++xx) cin >> x[xx];

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;

using vi = vector<int>;
using vll = vector<ll>;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

int main()
{ _
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        set<int> S = {6, 10, 14};
        set<int> T = {6, 10, 15};
        int s = 6 + 10 + 14, t = 6 + 10 + 15;

        if (n > s && S.count(n - s) == 0)
            cout << "YES\n6 10 14 " << (n - s) << endl;
        else if (n > t && T.count(n - t) == 0)
            cout << "YES\n6 10 15 " << (n - t) << endl;
        else
            cout << "NO\n";
    }
    exit(0);
}