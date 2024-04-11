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
ll c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        if (a > b) swap(a, b);

        n = 2 * (b - a);
        if (a >= n + 1 || b >= n + 1 || c >= n + 1) {
            cout << -1 << nl; continue;
        }

        res = (c + n / 2 - 1) % n + 1;
        cout << res << nl;
    }

    return 0;
}