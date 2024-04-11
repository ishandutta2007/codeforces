#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 60

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b[maxn], mn, f[30], r, tot;
vector<ll> ch;
string s, o;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> s >> m; n = s.size(); r = 25; o = s;
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }

        for (i = 0; i < 26; i++) f[i] = 0;
        for (i = 0; i < n; i++) f[(ll)s[i] - 97]++;
        // for (i = 0; i < 26; i++) cout << b[i] << ' ';
        // cout << nf;

        tot = m;
        while (tot) {
            // for (i = 0; i < m; i++) cout << b[i] << ' ';
            // cout << nf;
            mn = INF; k = 0; ch.clear();
            for (i = 0; i < m; i++) mn = min(mn, b[i]);
            // cout << mn << nf;
            for (i = 0; i < m; i++) {
                // for (j = 0; j < 26; j++) cout << b[j] << ' ';
                // cout << nf;
                // cout << i << ' ' << b[i] << nf;
                if (b[i] == mn) {
                    k++; ch.pb(i);
                }
            }
            // cout << nf;

            // cout << k << nf;
            while (f[r] < k) r--;
            // cout << r << nf;
            for (auto u : ch) {
                o[u] = (char)r + 97; b[u] = INF; tot--;
                for (i = 0; i < m; i++) b[i] -= abs(i - u);
            }
            r--;
            // cout << "tot = " << tot << nf;
        }

        for (i = 0; i < m; i++) cout << o[i];
        cout << nl;
    }

    return 0;
}