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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
vector<ll> v;

ll m1[9] = {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    for (i = 0; i < 9; i++) {
        for (j = 1; j <= 9; j++) {
            v.pb(m1[i] * j);
        }
    }

    cin >> t;
    while (t--) {
        cin >> n; res = 0;
        for (auto u : v) {
            if (u <= n) res++;
        }

        cout << res << nl;
    }

    return 0;
}