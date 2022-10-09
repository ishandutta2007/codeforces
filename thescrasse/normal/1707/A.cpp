#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll rs[maxn], x;

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
            cin >> a[i]; rs[i] = 0;
        }

        x = 0;
        for (i = n; i >= 1; i--) {
            if (x == k) {
                rs[i] = (a[i] <= k);
            } else {
                rs[i] = 1; x += (a[i] > x);
            }
        }

        /* for (i = 1; i <= n; i++) {
            if (k > 0 && rs[i] == 0) rs[i] = 1, k--;
        } */

        for (i = 1; i <= n; i++) cout << rs[i];
        cout << nl;
    }

    return 0;
}