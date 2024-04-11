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

bool eq(char a, char b) {
    return a == b || a == '#' || b == '#';
}

void solve() {
    string s, t; cin >> s >> t;
    int n = sz(s), m = sz(t); int q = m;
    while(m < n) t.pb('#'), ++m;
    vector<vi> dp(n, vi(n));

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j + i < n; ++j) {
            const int r = i + j;
            if(eq(s[i], t[j])) dp[j][r] += i ? dp[j+1][r] : 1, dp[j][r] %= MOD;
        }
        for(int j = i; j < n; ++j) {
            const int l = j - i;
            if(eq(s[i], t[j])) dp[l][j] += i ? dp[l][j-1] : 1, dp[l][j] %= MOD;
        }

        if(i >= q - 1) ans = (ans + dp[0][i]) % MOD;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    rng.seed(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    while(t--) solve();
}