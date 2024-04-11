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
        cin >> n; res = 0;

        if (n == 2) {
            cout << 1 << nl;
            cout << 2 << ' ' << 1 << nl;
            cout << 1 << nl;
            cout << 2 << ' ' << 1 << nl;
            continue;
        }

        if (n == 3) {
            cout << 5 << nl;
            cout << 2 << ' ' << 3 << ' ' << 1 << nl;
            cout << 2 << nl;
            cout << 1 << ' ' << 3 << nl;
            cout << 3 << ' ' << 2 << nl;
            continue;
        }

        a[(n + 1) / 2] = 1; a[n] = 2; k = 3;
        for (i = 2; i <= (n - 1) / 2; i++) {
            a[i] = k; k++; res += (n - i) * (n - i);
        }

        a[1] = k; k++;
        for (i = (n + 3) / 2; i <= n - 1; i++) {
            a[i] = k; k++; res += (i - 1) * (i - 1);
        }

        res += (n - 1) * (n - 1);
        k = (n + 1) / 2;
        res += (n - k) * (n - k);

        cout << res << nl;

        for (i = 1; i <= n; i++) cout << a[i] << ' ';
        cout << nl;

        cout << n - 1 << nl;

        for (i = 2; i <= (n + 1) / 2; i++) {
            cout << i _ n << nl;
        }

        for (i = (n + 3) / 2; i <= n - 1; i++) {
            cout << i _ 1 << nl;
        }

        cout << 1 _ n << nl;
    }

    return 0;
}