// 417E
// Square Table

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 1000000007
#define maxn 110

ll sq(ll x) {
    for (ll i = 1;; i++) {
        if (i * i > x) return (i - 1) * (i - 1);
    }
}

ll i, i1, j, k, k1, t, n[2], m, res, flag[10], a[2][maxn], b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n[0] >> n[1];
    for (i = 0; i < 2; i++) {
        if (n[i] == 3) {
            a[i][0] = 2; a[i][1] = 3; a[i][2] = 6;
        } else {
            b = sq(n[i]); k = n[i] - b;
            for (j = 0; j < k; j++) {
                a[i][j] = 3; a[i][j + k] = 4;
            }
            for (j = 2 * k; j < n[i]; j++) a[i][j] = 5;
        }
    }

    for (i = 0; i < n[0]; i++) {
        for (j = 0; j < n[1]; j++) {
            cout << a[0][i] * a[1][j] << ' ';
        }
        cout << nl;
    }

    return 0;
}