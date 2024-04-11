#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //  .
#include <ext/pb_ds/tree_policy.hpp>
#include <stdint.h>

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
const int MOD = 998244353;

int pow(int j, int n) {
    int res = 1;
    for(; n != 0; n >>= 1, j = (ll)j*j%MOD)
        if(n&1) res = (ll)res*j%MOD;
    return res;
}

void solve() {
    int n, k, m; cin >> n >> k >> m;
    vector<vpi> cond(n+1);
    while(m--) {
        int l, r, x; cin >> l >> r >> x;
        cond[r-1].eb(l-1, x);
    }

    int ans = 1;
    for(int i = 0; i < k; ++i) {
        vi v(n+1), d(n+1), st;
        for(int j = 0; j < n; ++j) {
            st.pb(j);
            for(auto [l, x] : cond[j]) {
                if(((x>>i)&1) == 0) continue;
                while(!st.empty() && st.back() >= l) v[st.back()] = 1, st.pop_back();
            }
        }

        for(int j = 0, f = -1, s = 1; j <= n; ++j) {
            if(j) for(auto [l, x] : cond[j-1]) {
                if(((x>>i)&1) == 1) continue;
                if(f < 0) ++f, s = (s + MOD - 1) % MOD;
                while(f < l) s = (s - d[f++] + MOD)%MOD;
            }

            if(v[j]) d[j] = 0;
            else d[j] = s;
            s = (s+d[j])%MOD;
        }

        ans = (ll)ans*d[n]%MOD;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}