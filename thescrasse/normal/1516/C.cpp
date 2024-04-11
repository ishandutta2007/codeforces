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
bitset<200010> kn;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i]; k += a[i];
    }

    while (true) {
        flag[0] = 1;
        for (i = 1; i <= n; i++) {
            if (a[i] % 2) flag[0] = 0;
        }

        if (flag[0] == 0) break;
        for (i = 1; i <= n; i++) a[i] /= 2;
        k /= 2;
    }

    kn[0] = 1;
    for (i = 1; i <= n; i++) {
        kn |= (kn << a[i]);
    }

    if (k % 2 || kn[k / 2] == 0) {
        cout << 0 << nl; return 0;
    }

    cout << 1 << nl;
    for (i = 1; i <= n; i++) {
        if (a[i] % 2) {
            cout << i << nl; break;
        }
    }

    return 0;
}