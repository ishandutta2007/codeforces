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

ll rxor(ll x) {
    ll i, r = 0;
    for (i = 29; i >= 0; i--) {
        if (i == 0) {
            if (x % 4 == 1 || x % 4 == 2) r++;
            continue;
        }
        if (x % (1 << (i + 1)) >= (1 << i) && x % 2 == 0) r += (1 << i);
    }
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    // for (i = 0; i <= 15; i++) cout << i _ rxor(i) << nl;

    cin >> t;
    while (t--) {
        cin >> a >> b;
        k = rxor(a - 1);
        // cout << "a, b, r = " << a _ b _ rxor(a - 1) << nl;
        if (k == b) cout << a << nl;
        else if (k == (b ^ a)) cout << a + 2 << nl;
        else cout << a + 1 << nl;
    }

    return 0;
}