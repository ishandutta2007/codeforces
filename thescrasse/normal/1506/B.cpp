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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
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
        cin >> n >> k >> s; s = '#' + s;

        v.clear(); v.pb(-1);
        for (i = 1; i <= n; i++) {
            if (s[i] == '*') v.pb(i);
        }

        res = 0; m = -INF; n = v.size(); n--;
        for (i = 2; i <= n + 1; i++) {
            if (v[i] - m > k || i == n + 1) {
                m = v[i - 1]; res++;
            }
        }

        cout << res << nl;
    }

    return 0;
}