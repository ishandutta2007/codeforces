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
        cin >> n; flag[0] = 1;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] != i) flag[0] = 0;
        }

        if (flag[0] == 1) cout << 0 << nl;
        else if (a[1] == 1 || a[n] == n) cout << 1 << nl;
        else if (a[1] == n && a[n] == 1) cout << 3 << nl;
        else cout << 2 << nl;
    }

    return 0;
}