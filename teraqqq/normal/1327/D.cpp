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
const int N = 2e5+7;

int md[N+1];
vi d[N+1];

void get_div(int n, vi& res, int m = 1) {
    if(n == 1) res.pb(m);
    else {
        int t = md[n], k = 0;
        while(md[n] == t) n /= t, ++k;
        for(int i = 0; i <= k; ++i)
            get_div(n, res, m), m *= t;
    }
}

void solve() {
    int n; cin >> n;
    vi p(n), c(n), u(n);
    for(int& x : p) cin >> x, --x;
    for(int& x : c) cin >> x;

    int ans = INF;
    for(int i = 0; i < n; ++i)  {
        if(u[i]) continue;
        u[i] = 1;
        vi v { c[i] };
        for(int j = p[i]; j != i; j = p[j])
            v.pb(c[j]), u[j] = 1;

        const int m = v.size();
        for(int dx : d[m]) {
            if(ans <= dx) continue;
            for(int i = 0; i < dx; ++i) {
                bool ok = 1;
                for(int j = i; j < m; j += dx)
                    if(v[i] != v[j]) { ok = 0; break; }
                if(ok) { ans = dx; break; }
            }
        }

    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    for(int i = 2; i*i <= N; ++i) {
        if(!md[i]) {
            md[i] = i;
            for(int j = i*i; j <= N; j += i)
                md[j] = md[j] ? min(md[j], i) : i;
        }
    }
    for(int i = 2; i <= N; ++i)
        if(!md[i]) md[i] = i;
    for(int i = 1; i <= N; ++i)
        get_div(i, d[i]);

    int t; cin >> t;
    while(t--) solve();
}