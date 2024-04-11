#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, f[30], tk[30], d, r, tot;
string s;
priority_queue<array<ll, 2>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> k >> s;
        for (i = 0; i < 26; i++) {
            f[i] = 0; tk[i] = 1;
        }
        for (i = 0; i < n; i++) f[(ll)s[i] - 97]++;

        tot = 0;
        for (d = 1; d <= k; d++) {
            while (!pq.empty()) pq.pop();
            if (k % d != 0) continue;
            // cout << d << nl;
            for (i = 0; i < 26; i++) {
                pq.push({f[i], i}); tk[i] = 1;
            }
            r = d; res = INF;
            while (r--) {
                res = pq.top()[0]; b = pq.top()[1]; pq.pop();
                tk[b]++; pq.push({f[b] / tk[b], b});
                // cout << res << ' ' << b << "; ";
            }
            tot = max(tot, d * res);
            // cout << nl;
        }
        // cout << "---" << nl;

        cout << tot << nl;
    }

    return 0;
}