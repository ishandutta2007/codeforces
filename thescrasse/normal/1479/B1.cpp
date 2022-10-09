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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, x, y;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (i = 1; i <= n; i++) {
        k = a[i];
        if (k == x && k == y) continue;

        res++;
        if (k == x || k == y) {
            x = k; y = k; continue;
        }

        if (i == n) continue;
        if (a[i + 1] == x) x = k;
        else y = k;
    }

    cout << res << nl;

    return 0;
}