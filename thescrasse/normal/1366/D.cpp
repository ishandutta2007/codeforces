#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 500010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, er[10000010], r[maxn][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    for (i = 0; i <= 10000000; i++) {
        er[i] = i;
    }
    for (i = 2; i <= 10000000; i++) {
        if (er[i] != i) continue;
        for (j = 2 * i; j <= 10000000; j += i) {
            er[j] = i;
        }
    }

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (i = 0; i < n; i++) {
        m = a[i]; k = er[m];
        // cout << m << ' ' << k << nl;
        r[i][0] = k; m /= k;
        while (m % k == 0) {
            r[i][0] *= k; m /= k;
        }
        r[i][1] = a[i] / r[i][0];
        if (r[i][1] == 1) {
            r[i][0] = -1; r[i][1] = -1;
        }
    }

    for (i = 0; i < n; i++) {
        cout << r[i][0] << ' ';
    }
    cout << nl;
    for (i = 0; i < n; i++) {
        cout << r[i][1] << ' ';
    }

    return 0;
}