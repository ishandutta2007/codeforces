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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, vl[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n;
        if (n > 45) {
            cout << -1 << nl; continue;
        }

        k = 0;
        for (i = 9; i >= 1; i--) {
            k += i; vl[k] = 10 - i;
        }

        for (i = 44; i >= 1; i--) {
            if (vl[i] == 0) vl[i] = vl[i + 1];
        }

        k = 0;
        for (i = 0; i < vl[n] - 1; i++) {
            k += 9 - i;
        }

        cout << n - k;
        for (i = 0; i < vl[n] - 1; i++) {
            cout << 11 + i - vl[n];
        }
        cout << nl;
    }

    // for (i = 1; i <= 50; i++) cout << i << nl;

    return 0;
}