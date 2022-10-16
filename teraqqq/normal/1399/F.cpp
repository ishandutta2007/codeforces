#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define mp make_pair

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;

const int INF = 1e9;
const ll LINF = 1e18;

void solve() {
    int n; cin >> n;
    vector<pi> s(n); vi v(1, -INF);
    for(pi& x : s) {
        cin >> x.F >> x.S;
        v.pb(x.F), v.pb(x.S);
    }
    int m = 2*n+1;
    vector<vi> dp(m, vi(m)), l(m);

    sort(v.begin(), v.end());
    for(pi& x : s) {
        x.F = lower_bound(v.begin(), v.end(), x.F) - v.begin();
        x.S = lower_bound(v.begin(), v.end(), x.S) - v.begin();
        l[x.S].pb(x.F);
    }

    for(int i = 1; i < m; ++i) {
        for(int j = 0; j <= i; ++j)
            dp[j][i] = dp[j][i-1];

        sort(l[i].begin(), l[i].end(), greater<int>());

        for(int x : l[i]) {
            ++dp[x][i];
            for(int j = x; j--; ) {
                dp[j][i] = max(dp[j][i], dp[j][x-1] + dp[x][i]);
                dp[j][i] = max(dp[j][i], dp[j+1][i]);
            }
        }
    }
    cout << dp[0][m-1] << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while(t--) solve();
}