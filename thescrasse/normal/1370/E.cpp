#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 1000010

ll i, i1, j, k, k1, n, m, res, flag[10], a, b, sz, dp[maxn][2];
string s, t;
vector<ll> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> s >> t; flag[0] = 0;
    for (i = 0; i < n; i++) {
        if (s[i] == t[i]) {
            continue;
        } else if (s[i] == '0') {
            v.pb(0); flag[0]++;
        } else {
            v.pb(1); flag[0]--;
        }
    }

    if (flag[0] != 0) {
        cout << -1; return 0;
    }

    if (v.empty()) {
        cout << 0; return 0;
    } else {
        sz = v.size();
    }

    res = 0; dp[0][0] = 0; dp[0][1] = 0;
    for (i = 0; i < sz; i++) {
        if (v[i] == 0) {
            dp[i + 1][0] = dp[i][0] + 1;
            dp[i + 1][1] = max((ll)0, dp[i][1] - 1);
        } else {
            dp[i + 1][1] = dp[i][1] + 1;
            dp[i + 1][0] = max((ll)0, dp[i][0] - 1);
        }

        res = max(res, dp[i + 1][0] + dp[i + 1][1]);
    }

    cout << res;

    return 0;
}