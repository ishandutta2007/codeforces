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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; k = 0;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (i = 1; i <= n; i++) {
            if (a[i] != 0 && (i == 1 || a[i - 1] == 0)) k++;
        }

        if (k == 0) cout << 0 << nl;
        else if (k == 1) cout << 1 << nl;
        else cout << 2 << nl;
    }

    return 0;
}