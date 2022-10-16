#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define F first
#define S second
#define pb push_back
#define eb emplace_back

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return b > a ? a = b, true : false; }

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using ld = long double;
//using ii = __int128;

using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag,
                         tree_order_statistics_node_update>;

const int INF = 1e9+7;
const ll LINF = 1e18;

mt19937 rng;

ll a, b, c, d;

ll f(ll i) {
    ckmin(i, c/d);
    ckmax(i, 0LL);
    return (i+1)*a - b*d*i*(i+1)/2;
}

bool solve() {
    cin >> a >> b >> c >> d;
    if (a > b*c) {
        cout << -1 << '\n';
    } else {
        ll ans = f(0);
        ll j = (2*a-b*d)/(2*b*d);
        ckmax(ans, f(j-1));
        ckmax(ans, f(j));
        ckmax(ans, f(j+1));
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    rng.seed(chrono::steady_clock::now().time_since_epoch().count());
    int t; cin >> t; while(t--) solve();
}