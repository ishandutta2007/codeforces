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

int i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];

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
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }

        res = 0;
        for (i = 1; i <= n; i++) {
            b[i] = 1;
            for (j = i - 1; j >= 1; j--) {
                k = ((ll)a[j] * b[j + 1] + a[j + 1] - 1) / a[j + 1];
                while ((a[j] + (k + 99) - 1) / (k + 99) > a[j + 1] / b[j + 1]) k += 100;
                while ((a[j] + (k + 9) - 1) / (k + 9) > a[j + 1] / b[j + 1]) k += 10;
                while ((a[j] + k - 1) / k > a[j + 1] / b[j + 1]) k++;
                if (k == b[j]) break;
                res = (res + (ll)j * (n - i + 1) * (k - b[j])) % mod;
                b[j] = k;
            }

            /* for (j = 1; j <= i; j++) cout << b[j] << ' ';
            cout << nl; */
        }

        cout << res << nl;
    }

    return 0;
}