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
ll c, d;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        if (d > a + b + c - 3) cout << "NO" << nl;
        else if (d < max((ll)0, 2 * max({a, b, c}) - (a + b + c) - 1)) cout << "NO" << nl;
        else cout << "YES" << nl;
    }

    return 0;
}