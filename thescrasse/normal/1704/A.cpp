#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    ll t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        string s1, s2; cin >> s1 >> s2;
        s1 = '#' + s1; s2 = '#' + s2;

        vector<ll> flag(10, 0);
        for (ll i = 1; i <= n - m; i++) {
            if (s1[i] == '0') flag[0] = 1;
            else flag[1] = 1;
        }

        flag[2] = 1;
        for (ll i = 2; i <= m; i++) {
            if (s1[n - m + i] != s2[i]) flag[2] = 0;
        }

        if (flag[2] == 0) {
            cout << "NO" << nl; continue;
        }

        if (s1[n - m + 1] == s2[1] || flag[(ll)s2[1] - '0'] == 1) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}