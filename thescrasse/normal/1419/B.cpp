#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], p2[40], a[40], b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    a[1] = 1; p2[1] = 1;
    for (i = 2; i <= 30; i++) {
        p2[i] = 2 * p2[i - 1] + 1;
        a[i] = a[i - 1] + (p2[i] * (p2[i] + 1) / 2);
    }
    a[31] = INF + 1;

    cin >> t;
    while (t--) {
        cin >> n;
        k = 0;
        while (a[k + 1] <= n) k++;
        cout << k << nl;
    }

    return 0;
}