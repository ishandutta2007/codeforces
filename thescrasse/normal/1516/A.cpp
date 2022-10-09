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
        cin >> n >> k;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (i = 1; i <= k; i++) {
            for (j = 1; j <= n; j++) {
                if (a[j] != 0) {
                    a[j]--; a[n]++; break;
                }
            }
        }

        for (i = 1; i <= n; i++) cout << a[i] << ' ';
        cout << nl;
    }

    return 0;
}