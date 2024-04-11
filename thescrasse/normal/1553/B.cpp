#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 510

ll i, i1, j, k, k1, tc, n, m, res, flag[10], a, b;
string s, t, sr, o;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> tc;
    while (tc--) {
        cin >> s >> t; flag[0] = 0;
        sr = s; reverse(sr.begin(), sr.end());
        n = s.size(); m = t.size();
        s = '#' + s; sr = '#' + sr;
        for (i = 1; i <= n; i++) {
            for (j = i; j <= n; j++) {
                k = j - (m - (j - i + 1));
                if (k <= 0 || k >= j + 1) continue;

                o = s.substr(i, j - i + 1) + sr.substr(n - j + 2, (n - k + 1) - (n - j + 2) + 1);
                if (o == t) flag[0] = 1;

                // cout << i _ j _ o << nl;
            }
        }

        if (flag[0] == 1) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}