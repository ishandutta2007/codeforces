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

void solve() {
    vi a(6); for(int& x : a) cin >> x;
    int n; cin >> n;
    vi b(n); for(int& x : b) cin >> x;
    sort(all(a)), sort(all(b));

    int ans = INF;
    for(int j = 0; j < 6; ++j) {
        set<pair<int, pi>> s;
        for(int i = 0; i < n; ++i)
            s.insert({b[i] - a[5], {i, 5}});

        bool ok = true;
        for(int i = 0; i < n; ++i) {

            const int k = b[i] - a[j]; // k is min!

            while(s.begin()->F < k) {
                const int i = s.begin()->S.F;
                const int j = s.begin()->S.S;
                s.erase(s.begin());
                if(!j) { ok = false; break; }
                s.insert({b[i] - a[j-1], {i, j-1}});
            }
            if(!ok) break;

            const int m = prev(s.end())->F;
            ckmin(ans, m - k);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    rng.seed(chrono::steady_clock::now().time_since_epoch().count());
    //int t; cin >> t; while(t--) solve();
    solve();
}