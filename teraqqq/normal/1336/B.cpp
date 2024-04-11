#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //  .
#include <ext/pb_ds/tree_policy.hpp>

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define rsz resize
#define mp make_pair

#define sz(x) ((int)(x).size())
#define all(x)  (x).begin(),  (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;

using ld = double;
using cd = complex<ld>;
using vcd = vector<cd>;

template<class T> using ordered_set = tree<T, null_type, less<T>,
                         rb_tree_tag, tree_order_statistics_node_update>;
template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return b > a ? a = b, true : false; }

const int INF = 1e9;
const ll LINF = 3e18;
const int MOD = 998244353;

mt19937 rng;

const int N = 2e5+7;

ll sqr(ll x) { return x*x; }
ll get_ans(vi& a, vi& b, vi& c) {
    ll res = LINF;
    for(int i = 0, j = 0, k = 0; i < sz(a); ++i) {
        ckmin(res, sqr((ll)a[i]-b[j]) + sqr((ll)a[i]-c[k]) + sqr((ll)c[k]-b[j]));
        for(; j+1 < sz(b) && b[j+1] <= a[i]; ) {
            ++j;
            ckmin(res, sqr((ll)a[i]-b[j]) + sqr((ll)a[i]-c[k]) + sqr((ll)c[k]-b[j]));
            while(k+1 < sz(c) && c[k+1] <= b[j]) {
                ++k;
                ckmin(res, sqr((ll)a[i]-b[j]) + sqr((ll)a[i]-c[k]) + sqr((ll)c[k]-b[j]));
            }
        }
    }
    return res;
}

void solve() {
    int na, nb, nc; cin >> na >> nb >> nc;
    vi a(na), b(nb), c(nc);
    for(int& x : a) cin >> x; sort(all(a));
    for(int& x : b) cin >> x; sort(all(b));
    for(int& x : c) cin >> x; sort(all(c));
    ll ans = LINF;
    ckmin(ans, min(get_ans(a, b, c), get_ans(a, c, b)));
    ckmin(ans, min(get_ans(b, a, c), get_ans(b, c, a)));
    ckmin(ans, min(get_ans(c, a, b), get_ans(c, b, a)));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    rng.seed(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t; cin >> t;
    while(t--) solve();
}