    #include <bits/stdc++.h>
    using namespace std;
     
    #define nl "\n"
    #define nf endl
    #define ll long long
    #define pb push_back
    #define _ << ' ' <<
     
    #define INF (ll)1e18
    #define mod 998244353
    #define maxn 100010
     
    ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, mx, cn;
    vector<array<ll, 2>> v;
     
    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
     
        #if !ONLINE_JUDGE && !EVAL
            ifstream cin("input.txt");
            ofstream cout("output.txt");
        #endif
     
        cin >> n; v.pb({-1, -1});
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }
        a[0] = a[2]; a[n + 1] = a[n - 1];
     
        for (i = 1; i <= n; i++) {
            if (a[i] < a[i - 1] && a[i] < a[i + 1]) v.pb({i, -1});
            else if (a[i] > a[i - 1] && a[i] > a[i + 1]) v.pb({i, 1});
        }
     
        // for (auto u : v) cout << u[0] _ u[1] << nl;
     
        m = v.size(); m--;
     
        for (i = 1; i <= m - 1; i++) mx = max(mx, v[i + 1][0] - v[i][0]);
        for (i = 1; i <= m - 1; i++) {
            if (v[i + 1][0] - v[i][0] == mx) cn++;
        }
        // cout << cn << nl;
     
        for (i = 2; i <= m - 1; i++) {
            // cout << i << nl;
            if (v[i][0] - v[i - 1][0] == v[i + 1][0] - v[i][0]) {
                // cout << 1 << nl;
                if (v[i][1] == 1) {
                    // cout << 2 << nl;
                    if ((v[i][0] - v[i - 1][0]) % 2 == 0) {
                        // cout << 3 << nl;
                        if (v[i][0] - v[i - 1][0] >= mx) {
                            // cout << 4 << nl;
                            if (cn == 2) {
                                // cout << 5 << nl;
                                res++;
                            }
                        }
                    }
                }
            }
        }
     
        cout << res << nl;
     
        return 0;
    }