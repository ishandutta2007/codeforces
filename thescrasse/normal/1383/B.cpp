#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, cb[50];

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
        for (i = 0; i < n; i++) cin >> a[i];

        for (i = 0; i <= 40; i++) cb[i] = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < 32; j++) {
                if ((a[i] >> j) & 1) cb[j]++;
            }
        }

        flag[0] = 0;
        for (i = 40; i >= 0; i--) {
            if (cb[i] % 2 == 0) continue;
            if (cb[i] % 4 == 1) {
                flag[0] = 1;
                cout << "WIN" << nl; break;
            } else if (n % 2 == 0) {
                flag[0] = 1;
                cout << "WIN" << nl; break;
            } else {
                flag[0] = 1;
                cout << "LOSE" << nl; break;
            }
        }

        if (flag[0] == 0) {
            cout << "DRAW" << nl;
        }
    }

    return 0;
}