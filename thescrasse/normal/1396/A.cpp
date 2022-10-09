#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, md;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n; md = n - 1;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 1 << ' ' << 1 << ' ' << nl << -a[0] << nl;
        cout << 1 << ' ' << 1 << ' ' << nl << 0 << nl;
        cout << 1 << ' ' << 1 << ' ' << nl << 0 << nl;
        return 0;
    }

    cout << 1 << ' ' << n << nl;
    for (i = 0; i < n; i++) {
        k = (md - a[i]) % md; k += md; k %= md;
        cout << n * k << ' ';
        a[i] += (n * k);
    }
    cout << nl;

    cout << 1 << ' ' << n - 1 << nl;
    for (i = 0; i < n - 1; i++) {
        cout << -a[i] << ' '; a[i] = 0;
    }
    cout << nl;

    cout << 2 << ' ' << n << nl;
    for (i = 1; i < n; i++) {
        cout << -a[i] << ' ';
    }
    cout << nl;

    return 0;
}