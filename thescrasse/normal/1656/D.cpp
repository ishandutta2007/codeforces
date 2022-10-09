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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; m = n; a = 2;
        while (n % 2 == 0) {
            a *= 2; n /= 2;
        }

        if (n != 1 && n <= 2000000000 && n * (n + 1) <= 2 * m) cout << n << nl;
        else if (a != 1 && a <= 2000000000 && a * (a + 1) <= 2 * m) cout << a << nl;
        else cout << -1 << nl;
    }

    return 0;
}