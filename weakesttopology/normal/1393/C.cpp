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

int solve()
{
    int n; cin >> n;
    int N = 1 << 18;
    vi M(N, 0);
    int m = 0;
    for (int i = 0; i < n; ++i)
    {
        int a; cin >> a;
        M[a]++;
        m = max(m, M[a]);
    }
    int c = 0;
    for (int a = 0; a < N; ++a)
        c += M[a] == m;

    int ans = c - 1 + (n - c * m) / (m - 1);
    return ans;
}

int main()
{ _
    int T; cin >> T;
    while (T--)
        cout << solve() << endl;
    exit(0);
}