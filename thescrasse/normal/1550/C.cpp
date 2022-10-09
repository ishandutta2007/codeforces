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

bool solve(ll l, ll r) {
    ll i, j, k, f = 1;
    for (i = l; i <= r; i++) {
        for (j = i + 1; j <= r; j++) {
            for (k = j + 1; k <= r; k++) {
                if (a[i] <= a[j] && a[j] <= a[k]) f = 0;
                if (a[i] >= a[j] && a[j] >= a[k]) f = 0;
            }
        }
    }
    return (f == 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; res = 0;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (i = 1; i <= n; i++) {
            for (j = i; j <= min(n, i + 10); j++) {
                if (solve(i, j)) res++;
            }
        }

        cout << res << nl;
    }

    return 0;
}