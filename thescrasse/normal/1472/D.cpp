#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; k = 0;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }

        sort(a + 1, a + n + 1); reverse(a + 1, a + n + 1);
        for (i = 1; i <= n; i++) {
            if (i % 2) {
                if (a[i] % 2 == 0) k += a[i];
            } else {
                if (a[i] % 2) k -= a[i];
            }
        }

        if (k > 0) cout << "Alice" << nl;
        else if (k == 0) cout << "Tie" << nl;
        else cout << "Bob" << nl;
    }

    return 0;
}