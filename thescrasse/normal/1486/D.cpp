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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], sm[maxn], bsl, bsm, bsu;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    bsl = 0; bsu = 1000000000;
    while (bsl != bsu) {
        bsm = (bsl + bsu + 1) / 2;
        for (i = 1; i <= n; i++) {
            if (a[i] >= bsm) b[i] = 1;
            else b[i] = -1;
        }

        for (i = 2; i <= n; i++) b[i] += b[i - 1];
        sm[n + 1] = -INF; sm[n + 2] = -INF;
        for (i = n; i >= 1; i--) sm[i] = max(b[i], sm[i + 2]);

        /* cout << bsm << nl;
        for (i = 1; i <= n; i++) cout << b[i] << ' ';
        cout << nl;
        for (i = 1; i <= n; i++) cout << sm[i] << ' ';
        cout << nl; */

        flag[0] = 0;
        for (i = 0; i <= n - k; i++) {
            // cout << i _ sm[i + k] _ b[i] << nl;
            if (sm[i + k] - b[i] - ((k + 1) % 2) >= 0) flag[0] = 1;
            if (i == n - k) continue;
            if (sm[i + k + 1] - b[i] - (k % 2) >= 0) flag[0] = 1;
        }

        if (flag[0] == 1) bsl = bsm;
        else bsu = bsm - 1;
    }

    cout << bsl << nl;

    return 0;
}