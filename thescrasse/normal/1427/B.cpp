#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, l;
string s;
vector<ll> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> k >> s; v.clear();

        l = 0;
        for (i = 0; i < n; i++) {
            if (s[i] == 'L') l++;
        }
        k = min(k, l);

        res = 0;
        for (i = 0; i < n; i++) {
            if (s[i] == 'W') res++;
            if (i == 0) continue;
            if (s[i] == 'W' && s[i - 1] == 'W') res++;
        }

        res += 2 * k;
        if (l == n && k > 0) res--;

        m = -INF;
        for (i = 0; i < n; i++) {
            if (s[i] == 'L') {
                m++;
            } else {
                if (m > 0) v.pb(m);
                m = 0;
            }
        }

        sort(v.begin(), v.end()); reverse(v.begin(), v.end());

        /* for (auto u : v) cout << u << ' ';
        cout << nl; */

        while (!v.empty() && v.back() <= k) {
            k -= v.back(); v.pop_back(); res++;
        }

        cout << res << nl;
    }

    return 0;
}