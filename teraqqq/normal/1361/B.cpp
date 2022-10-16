#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //  .
#include <ext/pb_ds/tree_policy.hpp>

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define rsz resize
#define mp make_pair

#define BK back()
#define FR front()

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using ld = double;

using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag,
                         tree_order_statistics_node_update>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

const int INF = 1e9;
const ll LINF = 1e18;
const ld PI = atan((ld)1)*4;

const int MOD = 1e9+7;

mt19937 rng;

ll fpow(ll a, int n) {
    ll res = 1;
    for(; n != 0; n >>= 1, a *= a)
        if(n&1) res *= a;
    return res < INF ? res : INF;
}

ll mpow(ll a, int n) {
    ll res = 1;
    for(; n != 0; n >>= 1, a = a*a%MOD)
        if(n&1) res = res*a%MOD;
    return res;
}

ll sgn(ll x) { return x ? x < 0 ? -1 : 1 : 0; }

void solve() {
    int n, p; cin >> n >> p;

    int MP = p > 1 ? log2((ld)INF) / log2((ld)p) : INF;

    ll disonans = 0, ans = 0;
    vi k(n); for(int& x : k) cin >> x;
    sort(rall(k));
    int prev = 1e7;
    for(int x : k) {
        if(disonans) {
            if(prev - x > MP) disonans = INF * sgn(disonans);
            else disonans *= fpow(p, prev - x);
            if(disonans > INF) disonans = INF;
            if(disonans < -INF) disonans = -INF;
        }

        //cout << x << ' ' << disonans << ' ' << ans << endl;
        //cout << mpow(p, x) << "! -> " << (disonans > 0 ? '-' : '+') << endl;

        if(disonans <= 0) ans += mpow(p, x), disonans++;
        else              ans -= mpow(p, x), disonans--;

        ans %= MOD; if(ans < 0) ans += MOD;
        prev = x;
    }

    if(disonans < 0 && ans) ans = MOD - ans;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    rng.seed(chrono::steady_clock::now().time_since_epoch().count());

    int t; cin >> t;
    //int t = 1;
    while(t--) solve();
}